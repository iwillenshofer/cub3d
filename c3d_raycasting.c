/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 14:10:09 by iwillens          #+#    #+#             */
/*   Updated: 2020/04/15 07:38:08 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** this part was inspired on the work of:
** Lode Vandevenne: https://lodev.org/cgtutor/raycasting.html
** and
** F. Permadi:
** https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/
**
**                       COORDINATE SYSTEM:
**								|
**	             | +   			|               0 | N
**				 |				|                 |
**    			 |				|                 |
**               |	          	|                 |
**  -         	 |(0,0)       +	|    W            |           90
**  -------------|-------------	|    -------------|-------------
**    			 |				|    270          |            E
**    			 |				|                 |
**       		 |				|                 |
**       		 |				|                 |
**       		 |- 			|               S | 180
*/

/*
** the calculate_rays determines the following values:
** 1. the direction of each ray;
** 4. the lenght of the ray;
** ---------------------------------------------------------------------------
** 1.
** in order to calculate the direction of the ray, it takes into account the
** width of the plane of view (in this case, the screen), and determine the
** angle of the ray from the player position to each pixel (x). This is done
** by rotating the angle from -30 degrees to 30 degrees (for a FOV of 60
** degrees), starting at the player's original position. To do this from left
** to right, the following formula is applied:
** --------> (1 - (i / (screen_width / 2)) * -1))
** returns a value from -1 to 1 according to the relative position from
** i (pixel x) and the lenght of the screen. Multiplying by half the field
** of view (FOV/2), we get a value between (-30 and 30);
** ----------------------------------------------------------------------------
** 2.
** The next step is calculating how much is needed to find the next box both in
** Y and X direction. Naturally, moving front or sideways would increase would
** need a travel of 1 unit in the grid. But as the ray is going to be cast with
** an angle, this distance must be calculated with the following formula:
**
**	       DELTA DISTANCE                                 /| |
**  ddist.y = (1 * tan(angle));                          / | | 1 / tan(angle)
**  ddist.x = (1 / tan(angle));                         /  | |
**                                                     /a__| |
**                                   1 * tan(angle) >> -----
** ----------------------------------------------------------------------------
** 3.
** now we just need to calculate the distance from players current position to
** the next x and y (as players does not move whole steps, but fractions).
** Since it is just a fraction of the the calculated distance, it can be
** calculated like this:
**     ((double)(player pos) - (int)(player pos)) * game->rays.ddist.x.
** the initial part (the fraction of the player position) is stored in the
** the variables raysdistx and raysdisty, which will later be used to add
** "x many ddist" determining the final lenght of the ray before hitting a
** wall. It is as if the start length is said fraction.
** ----------------------------------------------------------------------------
** 4.At last, we will perform the Loop to find out how long the ray takes to
** find a square which is not 0.
*/

void			clear_screen(t_screen *screen)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < screen->w)
	{
		y = 0;
		while (y < screen->h)
		{
			write_pixel(screen, x, y, 0);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(screen->mlx, screen->win, screen->img, 0, 0);
}

void			calculate_stepdir(t_rays *ray)
{
	ray->step.x = 1;
	if (ray->dir.x >= 0)
		ray->sdist.x = (floor(ray->pos.x) + 1.0 - ray->pos.x) * ray->ddist.x;
	else
	{
		ray->step.x = -1;
		ray->sdist.x = (ray->pos.x - floor(ray->pos.x)) * ray->ddist.x;
	}
	ray->step.y = 1;
	if (ray->dir.y >= 0)
		ray->sdist.y = (floor(ray->pos.y) + 1.0 - ray->pos.y) * ray->ddist.y;
	else
	{
		ray->step.y = -1;
		ray->sdist.y = (ray->pos.y - floor(ray->pos.y)) * ray->ddist.y;
	}
	ray->pos.x = floor(ray->pos.x);
	ray->pos.y = floor(ray->pos.y);
}

void			perform_dda(t_game *game, t_rays *ray)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sdist.x <= ray->sdist.y)
		{
			ray->sdist.x += ray->ddist.x;
			ray->pos.x += ray->step.x;
			ray->side = 0;
			ray->wall = ray->step.x == 1 ? 2 : 3;
		}
		else
		{
			ray->sdist.y += ray->ddist.y;
			ray->pos.y += ray->step.y;
			ray->side = 1;
			ray->wall = ray->step.y == 1 ? 1 : 0;
		}
		if (game->map.worldmap[(int)ray->pos.x][(int)ray->pos.y] > 1)
			add_sprite(game, (int)ray->pos.x, (int)ray->pos.y);
		if (game->map.worldmap[(int)ray->pos.x][(int)ray->pos.y] == 1)
			hit = 1;
	}
}

void			calculate_pdist(t_game *game)
{
	if (game->rays.side == 0)
		game->rays.dist = (game->rays.pos.x - game->player.pos.x +
				(1.0 - game->rays.step.x) / 2.0) / game->rays.dir.x;
	else
		game->rays.dist = (game->rays.pos.y - game->player.pos.y +
					(1.0 - game->rays.step.y) / 2.0) / game->rays.dir.y;
	game->rays.pdist = cos(fabs(game->rays.angle_x) * RADIAN) *
													game->rays.dist;
}

void			calculate_rays(t_game *game)
{
	int i;

	i = 0;
	clear_sprites(game);
	while (i < game->screen.w)
	{
		game->rays.angle_x = (atan2(i - game->screen.w / 2,
								game->player.plane_dist) / RADIAN);
		rotate_horizontal(game->rays.angle_x, game->player.dir,
												&game->rays.dir);
		game->rays.ddist.x = fabs(1.0 / game->rays.dir.x);
		game->rays.ddist.y = fabs(1.0 / game->rays.dir.y);
		game->rays.pos = game->player.pos;
		calculate_stepdir(&game->rays);
		perform_dda(game, &game->rays);
		calculate_pdist(game);
		drawtexture(game, i);
		game->rays.z_buffer[i] = game->rays.pdist;
		i++;
	}
	draw_sprites(game);
	mlx_put_image_to_window(game->screen.mlx, game->screen.win,
												game->screen.img, 0, 0);
}
