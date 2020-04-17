/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 07:41:13 by iwillens          #+#    #+#             */
/*   Updated: 2020/01/26 21:59:21 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int			ft_toupper(int c)
{
	if (my_islower(c))
		return (c - 32);
	return (c);
}
