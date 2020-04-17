/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_gfx_texture_draw.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 14:51:23 by iwillens          #+#    #+#             */
/*   Updated: 2020/04/15 07:46:58 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			write_pixel(t_screen *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)pixel = color;
}

void			drawceiling(t_game *game, int x, int start)
{
	int i;

	i = 0;
	while (i < start)
	{
		write_pixel(&game->screen, x, i, game->color_c);
		i++;
	}
}

void			drawroof(t_game *game, int x, int end)
{
	while (end < game->screen.h)
	{
		write_pixel(&game->screen, x, end, game->color_f);
		end++;
	}
}

void			get_texture_data(t_game *game, t_intxy *line, t_intxy *tex)
{
	double	wallx;
	int		lineheight;

	if (game->rays.side == 0)
		wallx = game->player.pos.y + game->rays.dist * game->rays.dir.y;
	else
		wallx = game->player.pos.x + game->rays.dist * game->rays.dir.x;
	wallx -= floor(wallx);
	tex->x = (int)(wallx * (double)(game->textures[game->rays.wall].width));
	lineheight = (int)(game->screen.h / game->rays.pdist);
	line->x = (-lineheight / 2 + game->screen.h / 2);
	line->y = (lineheight / 2 + game->screen.h / 2);
}

/*
** line.x is the start of the line. line.y is the end.
*/

void			drawtexture(t_game *game, int x)
{
	t_intxy line;
	int		color;
	t_intxy tex;
	int		i;

	get_texture_data(game, &line, &tex);
	drawceiling(game, x, line.x);
	drawroof(game, x, line.y);
	i = line.x;
	while (i < line.y)
	{
		if (i >= 0 && i < game->screen.h - 1)
		{
			tex.y = game->textures[game->rays.wall].height * (i - line.x) /
				(line.y - line.x);
			color = (unsigned int)get_texturepixel(game, tex.x, tex.y,
				game->rays.wall);
			write_pixel(&game->screen, x, i, color);
		}
		i++;
	}
}
