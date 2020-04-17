/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:59:22 by iwillens          #+#    #+#             */
/*   Updated: 2020/01/24 09:59:37 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s_src;
	unsigned char	*s_dst;

	if ((dst == NULL && src == NULL) || n == 0)
		return (dst);
	i = 0;
	s_dst = (unsigned char*)dst;
	s_src = (unsigned char*)src;
	while (i < n)
	{
		s_dst[i] = s_src[i];
		i++;
	}
	return (dst);
}
