/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 14:25:01 by iwillens          #+#    #+#             */
/*   Updated: 2020/04/15 07:55:34 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_replace(char *s, char find, char replace)
{
	int i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == find)
			s[i] = replace;
		i++;
	}
	return (s);
}
