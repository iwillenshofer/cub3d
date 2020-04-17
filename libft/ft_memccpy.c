/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:59:22 by iwillens          #+#    #+#             */
/*   Updated: 2020/01/21 20:02:18 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_src;
	unsigned char	*s_dst;

	i = 0;
	s_dst = (unsigned char*)dst;
	s_src = (unsigned char*)src;
	while (i < n)
	{
		s_dst[i] = s_src[i];
		if (s_dst[i] == (unsigned char)c)
			return (&s_dst[i] + 1);
		i++;
	}
	return ((void*)NULL);
}
