/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_mem_alloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 14:50:00 by iwillens          #+#    #+#             */
/*   Updated: 2020/04/15 07:41:15 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** allocates memory for the maximum number of sprites possible the map;
** which is the hipotenuse of map_h and map_w.
*/

void	mem_allocsprites(t_game *game)
{
	(void)game;
	game->rays.max_sprites = game->map.h * game->map.w;
	game->sprites = (t_sprites *)ft_calloc(game->rays.max_sprites,
														sizeof(t_sprites));
	game->rays.z_buffer = (double*)ft_calloc(game->screen.w + 1,
														sizeof(double));
}

int		**bmp_alloc(t_game *game)
{
	t_intxy pos;
	int		**bmp;

	bmp = (int**)ft_calloc(game->screen.w, sizeof(int*));
	pos.x = 0;
	while (pos.x < game->screen.w)
	{
		bmp[pos.x] = (int*)ft_calloc(game->screen.h, sizeof(int));
		pos.x++;
	}
	return (bmp);
}
