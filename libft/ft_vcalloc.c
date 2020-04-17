/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vcalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 01:45:54 by iwillens          #+#    #+#             */
/*   Updated: 2020/03/22 02:16:20 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** writes a value instead of a zero;
** always returns an integer array instead of void.
*/

int	*ft_vcalloc(size_t count, int value)
{
	size_t			i;
	int				*mem;

	i = 0;
	if (!(mem = (int*)malloc(count * sizeof(int))))
		return (NULL);
	while (i < count)
	{
		mem[i] = value;
		i++;
	}
	return (mem);
}
