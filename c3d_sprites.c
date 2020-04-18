/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 12:17:59 by iwillens          #+#    #+#             */
/*   Updated: 2020/04/14 21:37:09 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_sprites(t_game *game)
{
	int			i;
	t_sprites	tmp;

	i = 0;
	while (game->sprites[i].type != 0 && i < game->rays.max_sprites)
	{
		if (i < game->rays.max_sprites - 1 && game->sprites[i + 1].type != 0 &&
						game->sprites[i + 1].pdist > game->sprites[i].pdist)
		{
			tmp = game->sprites[i];
			game->sprites[i] = game->sprites[i + 1];
			game->sprites[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	clear_sprites(t_game *game)
{
	int i;

	i = 0;
	while (game->sprites[i].type != 0 && i < game->rays.max_sprites)
	{
		game->sprites[i].pdist = 0;
		game->sprites[i].type = 0;
		game->sprites[i].pos.x = 0;
		game->sprites[i].pos.y = 0;
		i++;
	}
}

void	add_sprite(t_game *game, int x, int y)
{
	int		i;
	int		type;
	t_xy	s;

	type = game->map.worldmap[x][y];
	i = 0;
	while (game->sprites[i].type != 0)
	{
		if (game->sprites[i].pos.x == x && game->sprites[i].pos.y == y)
			return ;
		i++;
	}
	game->sprites[i].pos.x = x;
	game->sprites[i].pos.y = y;
	game->sprites[i].type = type;
	s.x = game->sprites[i].pos.x + 0.5 - game->player.pos.x;
	s.y = game->sprites[i].pos.y + 0.5 - game->player.pos.y;
	game->sprites[i].pdist = sqrt(pow(s.x, 2) + pow(s.y, 2));
}

/*
** x = the center point of the sprite
** i.x = is the iaction between each point "x" to be drawn.
** i.y = each vertical pixel to be drawn
*/

void	draw_sprite_image(t_game *g, int z, int x)
{
	t_intxy			i;
	t_intxy			tex;
	t_intxy			start;
	unsigned int	color;

	i.x = x - g->sprites[z].draw_w / 2;
	start.x = i.x;
	while (i.x < x + g->sprites[z].draw_w / 2 && g->sprites[z].pos.x)
	{
		tex.x = g->textures[4].width * (i.x - start.x) / g->sprites[z].draw_w;
		i.y = (g->screen.h / 2) - (g->sprites[z].draw_h / 2);
		start.y = i.y;
		while (i.y < (g->screen.h / 2) + (g->sprites[z].draw_h / 2) &&
										i.x >= 0 && i.x <= g->screen.w)
		{
			tex.y = g->textures[4].height * (i.y - start.y) /
													g->sprites[z].draw_h;
			if (i.x > 0 && i.x < g->screen.w && i.y > 0 && i.y < g->screen.h
								&& g->sprites[z].pdist < g->rays.z_buffer[i.x])
				((color = get_tex_color(&g->textures[4], tex.x, tex.y)) &
				0x00FFFFFF) ? write_pixel(&g->screen, i.x, i.y, color) : 0;
			i.y++;
		}
		i.x++;
	}
}

void	draw_sprites(t_game *g)
{
	int z;
	int x;

	z = 0;
	sort_sprites(g);
	while (g->sprites[z].type != 0)
	{
		g->sprites[z].rel_pos.x = g->sprites[z].pos.x + 0.5 - g->player.pos.x;
		g->sprites[z].rel_pos.y = g->sprites[z].pos.y + 0.5 - g->player.pos.y;
		g->sprites[z].pdist = sqrt(pow(g->sprites[z].rel_pos.x, 2) +
											pow(g->sprites[z].rel_pos.y, 2));
		g->sprites[z].angle = ((atan2(g->sprites[z].rel_pos.x,
						g->sprites[z].rel_pos.y) / RADIAN)) -
						((atan2(g->player.dir.x, g->player.dir.y) / RADIAN));
		g->sprites[z].pdist = cos(fabs(g->sprites[z].angle) *
												RADIAN) * g->sprites[z].pdist;
		g->sprites[z].draw_h = (int)(g->screen.h / g->sprites[z].pdist);
		g->sprites[z].draw_w = (g->sprites[z].draw_h *
								g->textures[4].width) / g->textures[4].height;
		x = (tan(g->sprites[z].angle * RADIAN) * g->player.plane_dist) +
											((double)g->screen.w / 2.0);
		draw_sprite_image(g, z, x);
		z++;
	}
}
