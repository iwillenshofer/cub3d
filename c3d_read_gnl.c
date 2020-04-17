/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_read_gnl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:54:54 by iwillens          #+#    #+#             */
/*   Updated: 2020/04/15 07:29:36 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*gnl_join(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	int		j;
	char	*s;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s = ft_calloc(len1 + len2 + 1, sizeof(char));
	i = 0;
	while (i < len1)
	{
		s[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
	{
		s[i + j] = s2[j];
		j++;
	}
	if (s1)
		free(s1);
	return (s);
}

int		get_pos(char **str, char **line)
{
	int		pos;
	char	*tmp;

	pos = ft_findstr(*str, '\n');
	if (pos >= 0)
	{
		*line = ft_substr(*str, 0, pos);
		tmp = *str;
		*str = ft_substr(*str, pos + 1, ft_findstr(*str, '\0'));
		free(tmp);
		return (1);
	}
	else
	{
		*line = ft_substr(*str, 0, ft_findstr(*str, '\0'));
		free(*str);
		return (0);
	}
}

int		get_next_line(char **line, int fd)
{
	static char *str;
	char		buffer[BUFFER_SIZE + 1];
	int			ret;

	if (!line)
		return (-1);
	if (!(str) && !(str = ft_calloc(1, sizeof(char))))
		return (-1);
	while (ft_findstr(str, '\n') < 0 &&
		(ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		str = gnl_join(str, buffer);
	}
	return (get_pos(&str, line));
}
