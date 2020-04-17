/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_negative_tozero.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:19:30 by iwillens          #+#    #+#             */
/*   Updated: 2020/02/08 20:35:28 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This functions returns 0 if the number is negative,
**	or the original number it received if it is positive or 0;
*/

int	ft_negative_tozero(int n)
{
	if (n < 0)
		return (0);
	else
		return (n);
}

int	ft_negative_topositive(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}
