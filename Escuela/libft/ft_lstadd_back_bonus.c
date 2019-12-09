/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:51:51 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/28 17:50:43 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*act_list;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		lst[0] = new;
		return ;
	}
	act_list = *lst;
	while (act_list->next != NULL)
		act_list = act_list->next;
	act_list->next = new;
}
