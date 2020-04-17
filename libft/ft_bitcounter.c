/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitcounter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 20:43:14 by iwillens          #+#    #+#             */
/*   Updated: 2020/02/08 20:43:25 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** checks how many bits the integer is using
** so that we know how many characters (bytes) we'll need to
** print our unicode
*/

size_t	bit_counter(int c)
{
	size_t counter;

	counter = 0;
	if (c < 0)
		c = ~c;
	while (c)
	{
		c = c >> 1;
		counter++;
	}
	return (counter);
}
