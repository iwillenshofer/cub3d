/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:49:52 by iwillens          #+#    #+#             */
/*   Updated: 2020/02/09 19:47:44 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strfind_first(const char *str, const char *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (set[j] == str[i])
			{
				return (i + 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

size_t	ft_strfind_start(const char *str, const char *set)
{
	size_t	i;
	size_t	j;
	int		found;

	i = 0;
	found = 1;
	while (str[i] != '\0')
	{
		j = 0;
		found = 0;
		while (set[j] != '\0')
		{
			if (set[j] == str[i])
				found = 1;
			j++;
		}
		if (found == 0)
			break ;
		i++;
	}
	return (i);
}

size_t	ft_strfind_end(const char *str, const char *set)
{
	size_t	i;
	size_t	j;
	int		found;

	i = ft_strlen(str);
	found = 1;
	while (i--)
	{
		j = 0;
		found = 0;
		while (set[j] != '\0')
		{
			if (set[j] == str[i])
				found = 1;
			j++;
		}
		if (found == 0)
			break ;
	}
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;
	size_t	str_size;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = ft_strfind_start(s1, set);
	end = ft_strfind_end(s1, set);
	if (start >= end)
		str_size = 0;
	else
		str_size = end - start;
	if ((str = (char*)malloc((str_size) + 1)))
	{
		ft_memmove(str, s1 + start, str_size);
		str[str_size] = '\0';
		return (str);
	}
	return (NULL);
}
