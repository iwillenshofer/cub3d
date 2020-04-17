/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 02:34:37 by iwillens          #+#    #+#             */
/*   Updated: 2020/04/15 08:02:05 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** frees an array of strings.
*/

void			ft_free_strarray(char **s)
{
	int i;

	i = 0;
	while (s && s[i])
	{
		free(s[i]);
		i++;
	}
	if (s)
		free(s);
}
