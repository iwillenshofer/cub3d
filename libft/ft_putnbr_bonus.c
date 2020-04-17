/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 23:44:19 by iwillens          #+#    #+#             */
/*   Updated: 2020/02/04 01:58:08 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	unsigned int number;

	if (nb < 0)
	{
		ft_putchar('-');
		number = nb * -1;
	}
	else
		number = nb;
	if ((number / 10) > 0)
		ft_putnbr(number / 10);
	ft_putchar((number % 10) + '0');
}
