/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 07:03:56 by iwillens          #+#    #+#             */
/*   Updated: 2020/04/15 08:00:46 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_is_signednum(char *str)
{
	size_t	i;
	int		is_numeric;

	if (!str)
		return (0);
	i = 0;
	is_numeric = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			is_numeric = 0;
		i++;
	}
	return (is_numeric);
}
