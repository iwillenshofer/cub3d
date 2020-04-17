/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 21:18:10 by iwillens          #+#    #+#             */
/*   Updated: 2020/01/23 21:18:22 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int number;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		number = n * -1;
	}
	else
		number = n;
	if ((number / 10) > 0)
		ft_putnbr_fd(number / 10, fd);
	ft_putchar_fd((number % 10) + '0', fd);
}
