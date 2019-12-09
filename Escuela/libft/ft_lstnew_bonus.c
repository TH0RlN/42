/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 12:53:49 by rarias-p          #+#    #+#             */
/*   Updated: 2019/12/01 13:40:10 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new_list;

	new_list = NULL;
	if (!(new_list = malloc(sizeof(t_list))))
		return (0);
	new_list->content = (void *)content;
	new_list->next = NULL;
	return (new_list);
}
