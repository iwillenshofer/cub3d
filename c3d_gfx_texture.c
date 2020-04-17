/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_gfx_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:31:18 by iwillens          #+#    #+#             */
/*   Updated: 2020/04/15 07:54:09 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_tex_color(t_textures *tex, int x, int y)
{
	if (x >= 0 && x < tex->width
		&& y >= 0 && y < tex->height)
	{
		return (*(int*)(tex->img
			+ (4 * tex->width * y)
			+ (4 * x)));
	}
	return (0);
}

int		get_texturepixel(t_game *game, int x, int y, int index)
{
	char *color;

	color = (game->textures[index].img) + (game->textures[index].height * y *
	(game->textures[index].bpx / 8)) + (x * (game->textures[index].bpx / 8));
	if (color == 0)
		return (0);
	else
		return (*(int*)(color));
}

int		get_imagepixel(t_game *game, int x, int y)
{
	char *color;

	color = game->screen.addr + (y * game->screen.line_length + x *
		(game->screen.bits_per_pixel / 8));
	return (*(int*)(color));
}

int		load_texture(t_game *game, char *img_addr, int i)
{
	void *mlx;
	char *str;

	mlx = mlx_xpm_file_to_image(game->screen.mlx, img_addr,
		&game->textures[i].width, &game->textures[i].height);
	if (!mlx)
	{
		g_error_number = ERR_TEXTURE_NOLOAD;
		return (0);
	}
	str = mlx_get_data_addr(mlx, &game->textures[i].bpx,
		&game->textures[i].size_line, &game->textures[i].endian);
	if (!str)
	{
		g_error_number = ERR_TEXTURE_INVALID;
		return (0);
	}
	game->textures[i].mlx = mlx;
	game->textures[i].img = str;
	return (1);
}

/*
** textures 0 to 3 are the four walls.
** 4 is for Sprite.
*/

int		init_textures(t_game *game)
{
	int text_number;
	int i;

	text_number = 5;
	i = 0;
	game->textures = (t_textures*)ft_calloc(text_number, sizeof(t_textures));
	while (i < text_number)
	{
		if (!(load_texture(game, game->file.keys[i], i)))
			return (0);
		i++;
	}
	return (1);
}
