/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_mov_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:13:16 by iwillens          #+#    #+#             */
/*   Updated: 2020/04/15 07:40:02 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_game *g)
{
	if (g->map.worldmap[(int)(g->player.pos.x + g->player.dir.x *
			(g->walk_speed  * 4))][(int)(g->player.pos.y)] == 0)
		g->player.pos.x += g->player.dir.x * g->walk_speed;
	if (g->map.worldmap[(int)(g->player.pos.x)][(int)(g->player.pos.y +
			g->player.dir.y * (g->walk_speed * 4))] == 0)
		g->player.pos.y += g->player.dir.y * g->walk_speed;
}

void	move_down(t_game *g)
{
	if (g->map.worldmap[(int)(g->player.pos.x - g->player.dir.x *
			(g->walk_speed * 3))][(int)(g->player.pos.y)] == 0)
		g->player.pos.x -= g->player.dir.x * g->walk_speed;
	if (g->map.worldmap[(int)(g->player.pos.x)][(int)(g->player.pos.y -
			g->player.dir.y * (g->walk_speed  * 3))] == 0)
		g->player.pos.y -= g->player.dir.y * g->walk_speed;
}

void	move_left(t_game *g)
{
	rotate_horizontal(-90, g->player.dir, &g->player.dir);
	move_up(g);
	rotate_horizontal(90, g->player.dir, &g->player.dir);
}

void	move_right(t_game *g)
{
	rotate_horizontal(90, g->player.dir, &g->player.dir);
	move_up(g);
	rotate_horizontal(-90, g->player.dir, &g->player.dir);
}
