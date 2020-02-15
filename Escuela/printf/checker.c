/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 11:33:49 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/15 17:39:30 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	checker(t_rasa *tab)
{
	tab->type = get_type(tab);
	flagger(tab);
	if (!(tab->type == '%'))
		tab->data = va_arg(tab->list, void *);
	get_width(tab);
	if (tab->flags->dot > 0)
		get_precision(tab);
	print_type(tab);
}
