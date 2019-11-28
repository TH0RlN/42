/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:51:51 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/28 10:55:32 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*act_list;

	if (!alst || !new)
		return ;
	if (!*alst)
	{
		alst[0] = new;
		return ;
	}
	act_list = *alst;
	while (act_list->next != NULL)
		act_list = act_list->next;
	act_list->next = new;
}
