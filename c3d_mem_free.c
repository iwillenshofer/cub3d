/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_mem_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 12:56:37 by iwillens          #+#    #+#             */
/*   Updated: 2020/04/15 07:40:30 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		mem_freerays(t_game *game)
{
	if (game->rays.z_buffer == NULL)
		free(game->rays.z_buffer);
	game->rays.z_buffer = NULL;
}

void		mem_free_filedata(t_game *game)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (game->file.keys[i])
			free(game->file.keys[i]);
		i++;
	}
	ft_free_strarray(game->file.data);
	init_file(&game->file);
}

void		mem_freemap(t_game *game)
{
	t_map	*map;
	int		i;

	map = &game->map;
	i = 0;
	while (i < map->w)
	{
		if (map->worldmap[i])
			free(map->worldmap[i]);
		i++;
	}
	if (map->worldmap)
		free(map->worldmap);
	map->worldmap = NULL;
}

void		mem_freescreen(t_game *game)
{
	if (game->screen.img && game->screen.mlx)
		mlx_destroy_image(game->screen.mlx, game->screen.img);
	if (game->screen.win && game->screen.mlx)
		mlx_destroy_window(game->screen.mlx, game->screen.win);
}

void		mem_free_textures(t_game *game)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (game->textures)
		{
			if (game->textures[i].mlx)
				mlx_destroy_image(game->screen.mlx, game->textures[i].mlx);
		}
		i++;
	}
	if (game->textures)
		free(game->textures);
}
