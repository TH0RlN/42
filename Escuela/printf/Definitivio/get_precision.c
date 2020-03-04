/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:52:13 by rarias-p          #+#    #+#             */
/*   Updated: 2020/03/03 20:52:59 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_precision(t_rasa *tab)
{
	int i;

	if (tab->flags->astp > 0)
	{
		tab->flags->precision = (int)tab->data;
		if (tab->flags->precision < 0)
			tab->flags->dot = 0;
		tab->data = va_arg(tab->list, void *);
	}
	else
	{
		i = tab->pos;
		while (tab->format[i] != '.')
			i++;
		i++;
		while (tab->format[i] >= '0' && tab->format[i] <= '9')
		{
			tab->flags->precision = tab->flags->precision * 10
			+ (tab->format[i++] - '0');
		}
	}
}
