/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:40:30 by iwillens          #+#    #+#             */
/*   Updated: 2020/02/10 08:06:45 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	size_t			tot_bytes;
	unsigned char	*mem;

	i = 0;
	tot_bytes = count * size;
	if (!(mem = (unsigned char*)malloc(tot_bytes)))
		return (NULL);
	while (i < tot_bytes)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}
