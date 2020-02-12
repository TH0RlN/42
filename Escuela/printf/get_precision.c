/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:52:13 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/12 11:59:11 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_precision(t_rasa *tab)
{
	int i;

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
