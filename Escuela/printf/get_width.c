/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:33:59 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/12 12:32:38 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_width(t_rasa *tab)
{
	int	i;

	if (tab->flags->astw > 0)
	{
		tab->flags->width = (int)tab->data;
		tab->data = va_arg(tab->list, void *);
	}
	else
	{
		i = tab->pos;
		while (!(tab->format[i] >= '1' && tab->format[i] <= '9'))
			i++;
		while (tab->format[i] >= '0' && tab->format[i] <= '9')
			tab->flags->width = tab->flags->width * 10
			+ (tab->format[i++] - '0');
	}
}
