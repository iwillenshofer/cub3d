/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 06:57:13 by iwillens          #+#    #+#             */
/*   Updated: 2020/01/26 22:22:19 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

static int	my_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int			ft_isalpha(int c)
{
	if (my_isupper(c) || my_islower(c))
		return (1);
	return (0);
}
