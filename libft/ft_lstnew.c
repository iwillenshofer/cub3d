/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 21:55:37 by iwillens          #+#    #+#             */
/*   Updated: 2020/01/24 15:45:50 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*tmp;

	if (!(tmp = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (tmp)
		tmp->content = content;
	tmp->next = (t_list*)NULL;
	return (tmp);
}
