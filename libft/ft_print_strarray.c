/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strarray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 02:33:01 by iwillens          #+#    #+#             */
/*   Updated: 2020/04/15 07:55:44 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

/*
** Like ft_putstr, but used to print an array of strings.
** it loops until it finds a NULL element;
*/

void			ft_print_strarray(char **s)
{
	int i;
	int j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			write(1, &s[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
