/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:33:59 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/17 09:33:04 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_width(t_rasa *tab)
{
	int	i;

	if (tab->flags->astw > 0)
	{
		tab->flags->width = (int)tab->data > 0 ?
		(int)tab->data : (int)tab->data * -1;
		tab->flags->minus = (int)tab->data > 0 ?
		tab->flags->minus : tab->flags->minus + 1;
		tab->data = va_arg(tab->list, void *);
	}
	else
	{
		i = tab->pos;
		while (!(tab->format[i] >= '1' && tab->format[i] <= '9')
		&& tab->format[i] != tab->type)
		{
			if (tab->format[i] == '.')
				return ;
			i++;
		}
		while (tab->format[i] >= '0' && tab->format[i] <= '9')
			tab->flags->width = tab->flags->width * 10
			+ (tab->format[i++] - '0');
	}
}
