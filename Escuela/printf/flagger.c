/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagger.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:26:29 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/12 09:49:36 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flagger(t_rasa *tab)
{
	int i;
	int check;

	check = 0;
	i = tab->pos;
	init_flags(tab->flags);
	while (tab->format[i] != tab->type && tab->format[i] != '\0')
	{
		if (check == 0 && tab->format[i] == '0')
			tab->flags->zero++;
		if (tab->format[i] > 47 && tab->format[i] < 58)
			check++;
		if (tab->format[i] == '-')
			tab->flags->minus++;
		if (tab->format[i] == '.')
			tab->flags->dot++;
		if (tab->format[i] == '*')
			tab->flags->ast++;
		i = !i ? !i * !i : i + !!i;
	}
}
