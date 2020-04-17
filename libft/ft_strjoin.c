/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:48:32 by iwillens          #+#    #+#             */
/*   Updated: 2020/01/24 13:10:17 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	if ((str = (char*)malloc(size_s1 + size_s2 + 1)))
	{
		ft_memmove(str, s1, size_s1);
		ft_memmove(str + size_s1, s2, size_s2);
		str[size_s1 + size_s2] = '\0';
		return (str);
	}
	return (NULL);
}
