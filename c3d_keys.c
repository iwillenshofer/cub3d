/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:34:36 by iwillens          #+#    #+#             */
/*   Updated: 2020/04/15 07:42:01 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		close_button(t_game *game)
{
	exit_program(game, 1);
	return (0);
}

int		get_keystroke(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_button(game);
	if (keycode == KEY_LEFT)
		rotate_horizontal(-game->rotation_angle, game->player.dir,
											&game->player.dir);
	if (keycode == KEY_RIGHT)
		rotate_horizontal(game->rotation_angle, game->player.dir,
											&game->player.dir);
	if (keycode == KEY_W)
		move_up(game);
	if (keycode == KEY_S)
		move_down(game);
	if (keycode == KEY_A)
		move_left(game);
	if (keycode == KEY_D)
		move_right(game);
	calculate_rays(game);
	return (1);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->screen.win, X11_KEYPRESS, 1L << 0, get_keystroke, game);
	mlx_hook(game->screen.win, X11_DESTROY, 0, close_button, game);
}
