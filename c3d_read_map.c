/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 08:42:55 by iwillens          #+#    #+#             */
/*   Updated: 2020/04/14 22:40:08 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					set_player_pos(t_game *game, t_intxy pos, char c)
{
	if (game->player.pos.x != 0 || game->player.pos.y != 0)
	{
		g_error_number = ERR_PLAYER_POS_ALRSET;
		return (0);
	}
	game->player.pos.x = pos.x + 0.5;
	game->player.pos.y = (game->map.h - 1) - pos.y + 0.5;
	if (c == 'N')
		rotate_horizontal(ANGLE_N, game->player.dir, &game->player.dir);
	else if (c == 'S')
		rotate_horizontal(ANGLE_S, game->player.dir, &game->player.dir);
	else if (c == 'E')
		rotate_horizontal(ANGLE_E, game->player.dir, &game->player.dir);
	else if (c == 'W')
		rotate_horizontal(ANGLE_W, game->player.dir, &game->player.dir);
	return (1);
}

int					get_map_char(t_game *game, t_intxy pos, int start_map)
{
	char c;

	c = game->file.data[pos.y + start_map][pos.x];
	if (c == ' ')
		game->map.worldmap[pos.x][pos.y] = -1;
	else if (c == '0' || c == '1' || c == '2')
		game->map.worldmap[pos.x][pos.y] = c - '0';
	else if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
	{
		if (!(set_player_pos(game, pos, c)))
			return (0);
		game->map.worldmap[pos.x][pos.y] = 0;
	}
	else
	{
		g_error_number = ERR_MAP_UNKNOWN_CHAR;
		return (0);
	}
	return (1);
}

int					parse_map(t_game *game, int start_map)
{
	t_intxy pos;

	pos.x = 0;
	while (pos.x < game->map.w)
	{
		game->map.worldmap[pos.x] = (int*)ft_vcalloc(game->map.h, -1);
		pos.x++;
	}
	pos.y = 0;
	while (pos.y < game->map.h)
	{
		pos.x = 0;
		while (pos.x < game->map.w && game->file.data[pos.y + start_map][pos.x])
		{
			if (!(get_map_char(game, pos, start_map)))
				return (0);
			pos.x++;
		}
		pos.y++;
	}
	return (1);
}

/*
** map.x = start_map
** map.y = end_map
*/

int					read_map(t_game *game)
{
	char	**str;
	int		i;
	t_intxy map;

	i = 0;
	str = game->file.data;
	while (str[i] && (str[i][0] != ' ' && !ft_isdigit(str[i][0])))
		i++;
	map.x = i;
	while (str[i] && (str[i][0] == ' ' || ft_isdigit(str[i][0])))
		i++;
	map.y = i;
	game->map.w = get_width(str, map.x, map.y);
	game->map.h = map.y - map.x;
	game->map.worldmap = (int**)ft_calloc(game->map.w, sizeof(int*));
	if (!(parse_map(game, map.x)))
		return (0);
	if (str[i])
		g_error_number = ERR_MAP_LINE_SPACES;
	invert_map(game);
	if (!(check_validmap(&game->map)))
		g_error_number = ERR_MAP_INVALID;
	if (g_error_number != 0)
		return (0);
	return (1);
}
