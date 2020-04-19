/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_gfx_bmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 14:28:40 by iwillens          #+#    #+#             */
/*   Updated: 2020/04/15 07:50:49 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		little_endian(unsigned char *c, unsigned int value, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		c[i] = (char)(value >> (i * 8));
		i++;
	}
}

int			get_image_color(t_game *game, int x, int y)
{
	unsigned char	ccolor[4];
	unsigned int	color;

	if (x >= 0 && x < game->screen.w
		&& y >= 0 && y < game->screen.h)
	{
		color = *(unsigned int*)(game->screen.addr
			+ (4 * game->screen.w * y)
			+ (4 * x));
		little_endian(&ccolor[0], color, 4);
		return (*(int*)(ccolor));
	}
	return (0x0);
}

void		bmp_free(t_game *game, int **bmp)
{
	int i;

	i = 0;
	while (i < game->screen.w)
	{
		if (bmp[i])
			free(bmp[i]);
		i++;
	}
	if (bmp)
		free(bmp);
	bmp = NULL;
}

/*
** the bmp file structure was learnt from this tutorial:
** https://itnext.io/
**		bits-to-bitmaps-a-simple-walkthrough-of-bmp-image-format-765dc6857393
*/

void		bmp_write_header(t_game *game, int fd)
{
	unsigned char c[54];

	ft_bzero(&c, 54);
	c[0] = 'B';
	c[1] = 'M';
	little_endian(&c[10], 54, 4);
	little_endian(&c[14], 40, 4);
	little_endian(&c[18], game->screen.w, 4);
	little_endian(&c[22], game->screen.h, 4);
	little_endian(&c[26], 1, 2);
	little_endian(&c[28], 32, 2);
	write(fd, c, 54);
}

int			convert_to_bmp(t_game *game)
{
	int		fd;
	t_intxy pos;
	int		**bmp;

	fd = open("./imagem.bmp", O_WRONLY | O_APPEND | O_CREAT | O_TRUNC, 755);
	if (!fd)
		return (0);
	bmp = bmp_alloc(game);
	bmp_write_header(game, fd);
	pos.y = game->screen.h - 1;
	while (pos.y >= 0)
	{
		pos.x = 0;
		while (pos.x < game->screen.w)
		{
			bmp[pos.x][pos.y] = get_image_color(game, pos.x, pos.y);
			write(fd, &bmp[pos.x][pos.y], 4);
			pos.x++;
		}
		pos.y--;
	}
	close(fd);
	bmp_free(game, bmp);
	return (1);
}
