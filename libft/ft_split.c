/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:51:36 by iwillens          #+#    #+#             */
/*   Updated: 2020/02/09 19:46:11 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_splits(char const *s, char c)
{
	size_t i;
	size_t count;
	size_t strsize;

	i = 0;
	count = 0;
	strsize = 0;
	while (s[i])
	{
		if (s[i] == c && strsize > 0)
		{
			count++;
			strsize = 0;
		}
		if (s[i] != c)
			strsize++;
		i++;
	}
	if (i > 0)
		i--;
	if (s[i] && s[i] != c)
		count++;
	return (count);
}

static char		*allocate(const char *src, size_t start, size_t end)
{
	size_t	size_dst;
	size_t	i;
	char	*dst;

	i = 0;
	size_dst = end - start;
	if (!(dst = (char*)malloc(size_dst + 1)))
		return (NULL);
	ft_memmove(dst, &src[start] + i, size_dst);
	dst[size_dst] = '\0';
	return (dst);
}

static char		*get_singlestring(char const *s, size_t index, char c)
{
	size_t	counter;
	size_t	start;
	size_t	end;

	start = 0;
	end = 0;
	counter = 0;
	while (s[start] == c)
		start++;
	while (counter < index)
	{
		if (s[start] == c)
		{
			counter++;
			while (s[start] == c)
				start++;
		}
		else
			start++;
	}
	end = start;
	while (s[end] != '\0' && s[end] != c)
		end++;
	return (allocate(s, start, end));
}

char			**ft_split(char const *s, char c)
{
	char	**str;
	size_t	s_count;
	size_t	i;

	if (s == NULL)
		return (NULL);
	s_count = count_splits(s, c);
	if (!(str = (char**)malloc(sizeof(char*) * (s_count + 1))))
		return (NULL);
	i = 0;
	while (i < s_count)
	{
		if (!(str[i] = get_singlestring(s, i, c)))
			return (NULL);
		i++;
	}
	str[s_count] = 0;
	return (str);
}
