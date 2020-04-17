/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_gfx_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 21:47:42 by iwillens          #+#    #+#             */
/*   Updated: 2020/04/14 22:23:42 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** as minilibx for Linux does not have mlx_get_screen_size,
** a maximum screen size was set to 1920x1080.
** the actual code should be:
**	maxres_h = 0;
**	maxres_w = 0;
**	mlx_get_screen_size(game->screen.mlx, &maxres_w, &maxres_w);
*/

int	set_resolution(t_game *game, char *w, char *h)
{
	int maxres_h;
	int maxres_w;

	maxres_w = 1920;
	maxres_h = 1080;
	if (game->screen.h > 0 || game->screen.w > 0)
		return (0);
	game->screen.h = ft_atoi(h);
	game->screen.w = ft_atoi(w);
	if (game->screen.h > maxres_h)
		game->screen.h = maxres_h;
	if (game->screen.w > maxres_w)
		game->screen.w = maxres_w;
	return (1);
}

int	rgb_toint(char *r, char *g, char *b)
{
	int ir;
	int ig;
	int ib;
	int color;

	ir = atoi(r);
	ig = atoi(g);
	ib = atoi(b);
	color = (ir << 16) + (ig << 8) + ib;
	return (color);
}
