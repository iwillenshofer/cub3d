/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 12:59:21 by iwillens          #+#    #+#             */
/*   Updated: 2020/04/15 07:43:31 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		init_default(t_game *g)
{
	if (g->color_c == -1)
		g->color_c = 0x0000ff00;
	if (g->color_f == -1)
		g->color_f = 0x0000ff00;
	if (g->screen.w == 0)
		g->screen.w = 400;
	if (g->screen.h == 0)
		g->screen.h = 320;
	if (g->player.pos.x == 0 || g->player.pos.y == 0)
	{
		g_error_number = ERR_PLAYER_POS_NOTSET;
		return (0);
	}
	g->file.keys[0] == 0 ? g->file.keys[0] = ft_strdup("./tex/defNO.xpm") : 0;
	g->file.keys[1] == 0 ? g->file.keys[1] = ft_strdup("./tex/defSO.xpm") : 0;
	g->file.keys[2] == 0 ? g->file.keys[2] = ft_strdup("./tex/defWE.xpm") : 0;
	g->file.keys[3] == 0 ? g->file.keys[3] = ft_strdup("./tex/defEA.xpm") : 0;
	g->file.keys[4] == 0 ? g->file.keys[4] = ft_strdup("./tex/defS.xpm") : 0;
	g->player.plane_dist = ((double)(g->screen.w) / 2.0) /
											tan((g->screen.fov / 2) * RADIAN);
	return (1);
}

void	init_position(t_game *game)
{
	game->map.h = 0;
	game->map.w = 0;
	game->map.worldmap = NULL;
	game->screen.img = NULL;
	game->screen.win = NULL;
	game->screen.addr = NULL;
	game->rays.z_buffer = NULL;
	game->textures = NULL;
	game->color_c = -1;
	game->color_f = -1;
	game->player.pos.x = 0;
	game->player.pos.y = 0;
	game->screen.w = 0;
	game->screen.h = 0;
	game->screen.fov = 66;
	game->player.dir.x = 0;
	game->player.dir.y = 1;
	game->rotation_angle = 5;
	game->walk_speed = 0.22;
}

void	window_init(t_screen *screen)
{
	screen->win = mlx_new_window(screen->mlx, screen->w,
											screen->h, "Cub3d");
	screen->img = mlx_new_image(screen->mlx, screen->w, screen->h);
	screen->addr = mlx_get_data_addr(screen->img, &(screen->bits_per_pixel),
		&(screen->line_length), &(screen->endian));
	mlx_put_image_to_window(screen->mlx, screen->win, screen->img, 0, 0);
}

void	init_file(t_file *file)
{
	int i;

	file->data = NULL;
	i = 0;
	while (i < 5)
	{
		file->keys[i] = NULL;
		i++;
	}
}
