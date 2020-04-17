/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 07:44:01 by iwillens          #+#    #+#             */
/*   Updated: 2020/01/26 22:22:37 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int			ft_tolower(int c)
{
	unsigned int chr;

	chr = (unsigned int)c;
	if (my_isupper(chr))
		return (c + 32);
	return (chr);
}
