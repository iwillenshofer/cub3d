/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarray_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 02:37:39 by iwillens          #+#    #+#             */
/*   Updated: 2020/04/15 07:55:09 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** gets the number of elements in an array of strings.
*/

int				ft_strarray_size(char **str)
{
	int i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}
