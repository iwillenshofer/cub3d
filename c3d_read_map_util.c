/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_read_map_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 12:41:50 by iwillens          #+#    #+#             */
/*   Updated: 2020/04/14 21:46:21 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				print_map(t_game *game)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	write(1, "*****MAP*****\n", 14);
	while (i < game->map.h)
	{
		j = 0;
		while (j < game->map.w)
		{
			c = game->map.worldmap[j][i] + '0';
			write(1, &c, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	write(1, "*****MAP*****\n", 14);
}

/*
** since our coordinates increase as we go up and right, and the
** map array increases as we move down and right, we have to invert
** our map vertically to match our cartesians orientation.
*/

void				invert_map(t_game *game)
{
	int i;
	int j;
	int swap;

	i = 0;
	while (i < game->map.w)
	{
		j = 0;
		while (j < game->map.h / 2)
		{
			swap = game->map.worldmap[i][j];
			game->map.worldmap[i][j] =
				game->map.worldmap[i][game->map.h - j - 1];
			game->map.worldmap[i][game->map.h - j - 1] = swap;
			j++;
		}
		i++;
	}
}

/*
**	turn.x --> from 0 to 3;
**	turn.y --> multiplier (-1 or 1);
*/

int					check_borders(t_map *map, t_intxy pos)
{
	t_intxy xy;
	t_intxy increaser;
	t_intxy turn;

	turn.x = 0;
	turn.y = 1;
	while (turn.x <= 3)
	{
		xy = pos;
		increaser.x = (turn.x % 2 == 0) ? 1 : 0;
		turn.y = (turn.x >= 2) ? -1 : 1;
		while (xy.x >= 0 && xy.x < map->w && xy.y >= 0 && xy.y < map->h)
		{
			if (map->worldmap[xy.x][xy.y] == -1 || ((
				(xy.x == 0 || xy.x == map->w - 1) || (xy.y == 0
				|| xy.y == map->h - 1)) && map->worldmap[xy.x][xy.y] != 1))
				return (0);
			else if (map->worldmap[xy.x][xy.y] == 1)
				break ;
			xy.x += (increaser.x * turn.y);
			xy.y += (!(increaser.x) * turn.y);
		}
		turn.x++;
	}
	return (1);
}

int					check_validmap(t_map *map)
{
	t_intxy pos;
	int		c;

	pos.x = 0;
	while (pos.x < map->w)
	{
		pos.y = 0;
		while (pos.y < map->h)
		{
			c = map->worldmap[pos.x][pos.y];
			if (c > 1 || c == 0)
				if (!(check_borders(map, pos)))
					return (0);
			pos.y++;
		}
		pos.x++;
	}
	return (1);
}
