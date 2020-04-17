/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:09:55 by iwillens          #+#    #+#             */
/*   Updated: 2020/02/06 03:39:41 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t srcsize;

	if (dst == NULL || src == NULL)
		return ((size_t)NULL);
	i = 0;
	srcsize = ft_strlen(src);
	while (i <= srcsize && i < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	i--;
	if (dstsize > 0)
		dst[i] = '\0';
	return (srcsize);
}
