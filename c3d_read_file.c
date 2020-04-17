/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_read_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 21:00:00 by iwillens          #+#    #+#             */
/*   Updated: 2020/04/15 07:32:50 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>

/*
** adds 1 to the size of the string array, finishing with NULL;
*/

char			**read_realloc(char **str)
{
	int		size;
	char	**tmp;
	int		i;

	i = 0;
	if (!str)
		str = (char**)ft_calloc(1, sizeof(char*));
	tmp = str;
	size = ft_strarray_size(str);
	str = (char**)ft_calloc((size + 2), sizeof(char*));
	while (i < size)
	{
		str[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (str);
}

char			**read_file(char *filename)
{
	char	**str;
	char	*line;
	int		i;
	int		fd;
	int		ret;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
	{
		g_error_number = ERR_FILE_INVALIDFNAME;
		return (NULL);
	}
	i = 0;
	str = NULL;
	while ((ret = get_next_line(&line, fd)) >= 0)
	{
		str = read_realloc(str);
		str[i] = line;
		i++;
		if (ret == 0)
			break ;
	}
	close(fd);
	return (str);
}

/*
** gets the max line width of the file, to determine the
** width of the map.
*/

int				get_width(char **str, int start, int end)
{
	int width;
	int slen;

	width = 0;
	while (start < end)
	{
		slen = ft_strlen(str[start]);
		if (slen > width)
			width = slen;
		start++;
	}
	return (width);
}

int				load_file(t_game *game, char *filename)
{
	init_file(&game->file);
	if (!(game->file.data = read_file(filename)) ||
	(!(read_textures(game))) || (!(read_map(game))))
		return (0);
	return (1);
}
