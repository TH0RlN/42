/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 09:51:59 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/14 18:14:19 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_type2(t_rasa *tab, int i)
{
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
	if (tab->format[i] == '%')
		return ('%');
	return (0);
}

char	get_type(t_rasa *tab)
{
	int		i;
	char	k;

	i = ++tab->pos;
	while (tab->format[i] != ' ' && tab->format[i] != '\0')
	{
		if (tab->format[i] == 'c')
			return ('c');
		if (tab->format[i] == 's')
			return ('s');
		if (tab->format[i] == 'p')
			return ('p');
		if ((k = get_type2(tab, i)))
			return (k);
		i = !i ? !i * !i : i + !!i;
	}
	return (0);
}
