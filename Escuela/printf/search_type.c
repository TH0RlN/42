/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 09:51:59 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/10 09:59:49 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	search_type(t_rasa *tab)
{
	int i;

	i = 0;
	while (tab->format[i] != " ")
	{
		if (tab->format[i] == 'c')
			return ('c');
		if (tab->format[i] == 's')
			return ('s');
		if (tab->format[i] == 'p')
			return ('p');
		if (tab->format[i] == 'd')
			return ('d');
		if (tab->format[i] == 'i')
			return ('i');
		if (tab->format[i] == 'u')
			return ('u');
		if (tab->format[i] == 'x')
			return ('x');
		if (tab->format[i] == 'X')
			return ('X');
		i = !i ? !i * !i : i + !!i;
	}
	return (0);
}