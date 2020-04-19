/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_read_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 20:31:12 by iwillens          #+#    #+#             */
/*   Updated: 2020/04/14 22:23:27 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	floorcolor(t_game *game, int color, char type)
{
	if (type == 'F' && ((game->color_f == -1)))
		game->color_f = color;
	else if (type == 'C' && ((game->color_c == -1)))
		game->color_c = color;
	else
		return (0);
	return (1);
}

/*
**	i.x = counter
**	i.y = len
*/

int	check_arguments(t_game *game, char **s, t_file *file)
{
	const char	*al_keys[9] = {"NO", "SO", "WE", "EA", "S", "R", "F", "C"};
	const int	req_fields[9] = {2, 2, 2, 2, 2, 3, 4, 4};
	t_intxy		i;

	i.y = ft_strarray_size(s);
	i.x = 0;
	while (i.x < 8)
	{
		if (i.y >= 1 && ft_strncmp(*s, al_keys[i.x], ft_strlen(*s)) == 0)
		{
			if (i.y == req_fields[i.x] && i.y == 2 && ft_strlen(*s) ==
						ft_strlen(al_keys[i.x]) && file->keys[i.x] == 0)
			{
				file->keys[i.x] = ft_strdup(s[1]);
				return (1);
			}
			else if (i.y == 3 && i.x == 5 && ft_isnum(s[1]) && ft_isnum(s[2]))
				return (set_resolution(game, s[1], s[2]));
			else if (i.y == 4 && (i.x == 6 | i.x == 7) && ft_isnum(s[1]) &&
											ft_isnum(s[2]) && ft_isnum(s[3]))
				return (floorcolor(game, rgb_toint(s[1], s[2], s[3]), s[0][0]));
		}
		i.x++;
	}
	return (0);
}

/*
** c.x = first_comma
** c.y = second_comma
*/

int	check_commas(char *s, char **str, char commas)
{
	t_intxy c;
	char	*tmp;

	if ((ft_strncmp(str[0], "F", ft_strlen(str[0])) == 0 ||
			ft_strncmp(str[0], "C", ft_strlen(str[0])) == 0) && commas == 2)
	{
		while (!ft_isdigit(*s))
			s++;
		if ((c.x = ft_findstr(s, ',')) <= 0 ||
			(c.y = ft_findstr(s + c.x + 1, ',')) <= 0)
			return (0);
		tmp = s + c.x + 1;
		while (ft_isspace(*(tmp)))
			tmp++;
		if (!ft_isdigit(*tmp))
			return (0);
		tmp = s + c.x + c.y + 2;
		while (ft_isspace(*tmp))
			tmp++;
		if (!ft_isdigit(*tmp))
			return (0);
	}
	else if (commas != 0)
		return (0);
	return (1);
}

/*
** checks the file until numeric or equals space, which means
** the map has started
*/

int	compare_arguments(char *s, t_game *game)
{
	char	**str;
	int		ret;
	int		commas;
	char	*orig_str;
	int		i = 0;

	orig_str = ft_strdup(s);
	commas = ft_countchr(s, ',');
	str = ft_split(ft_replace(s, ',', ' '), ' ');
	if (ft_strarray_size(str) == 0)
	{
		free(str);
		free(orig_str);
		return (1);
	}
	ret = check_arguments(game, str, &game->file) *
		check_commas(orig_str, str, commas);
	free(orig_str);
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (ret);
}

int	read_textures(t_game *game)
{
	char	**s;
	int		i;

	i = 0;
	s = game->file.data;
	while (s && s[i] && !(ft_isdigit(s[i][0])) && s[i][0] != ' ')
	{
		if (!(compare_arguments(s[i], game)))
		{
			g_error_number = ERR_MAP_INVALIDARG;
			return (0);
		}
		i++;
	}
	return (1);
}
