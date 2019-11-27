/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:21:02 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/26 20:05:43 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *next_list;

	if (!lst || !(*lst) || !del)
		return ;
	while (*lst)
	{
		next_list = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = next_list;
	}
}
