/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:21:56 by iwillens          #+#    #+#             */
/*   Updated: 2020/04/15 08:00:53 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_insertchr_end(char *str, char c)
{
	char	*tmp;
	size_t	str_len;

	str_len = ft_strlen(str) + 1;
	tmp = (char*)malloc(sizeof(char) * (str_len + 1));
	ft_memcpy(tmp, str, str_len);
	tmp[str_len - 1] = c;
	tmp[str_len] = '\0';
	free(str);
	return (tmp);
}

char	*ft_insertchr_start(char *str, char c)
{
	char	*tmp;
	size_t	str_len;

	str_len = ft_strlen(str) + 1;
	tmp = (char*)malloc(sizeof(char) * (str_len + 1));
	ft_strlcpy(&tmp[1], str, str_len);
	tmp[0] = c;
	tmp[str_len] = '\0';
	free(str);
	return (tmp);
}

char	*ft_fillnchr_end(char *str, char c, size_t n)
{
	size_t str_len;

	str_len = ft_strlen(str);
	while (n < str_len)
	{
		str = ft_insertchr_end(str, c);
		n--;
	}
	return (str);
}

char	*ft_fillnchr_start(char *str, char c, size_t n)
{
	size_t	str_len;
	char	signal;

	signal = 0;
	if (n >= (str_len = ft_strlen(str)))
	{
		if (ft_issignednum(str) && (str[0] == '-' || str[0] == '+'))
		{
			if (str[0] == '-')
				signal = 1;
			else if (str[0] == '+')
				signal = 2;
			str[0] = '0';
		}
		while (n > str_len)
		{
			str = ft_insertchr_start(str, c);
			n--;
		}
		if (signal == 1)
			str = ft_insertchr_start(str, '-');
		if (signal == 2)
			str = ft_insertchr_start(str, '+');
	}
	return (str);
}
