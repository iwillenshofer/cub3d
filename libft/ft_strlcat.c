/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:05:34 by iwillens          #+#    #+#             */
/*   Updated: 2020/01/26 13:39:52 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t size_src;
	size_t size_dst;

	i = 0;
	size_src = 0;
	while (dst[i] && i < dstsize)
		i++;
	size_dst = i;
	while (dstsize > 0 && i < dstsize - 1 && (src[size_src] != '\0'))
	{
		dst[i] = src[size_src];
		i++;
		size_src++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	while (src[size_src] != '\0')
		size_src++;
	return (size_src + size_dst);
}
