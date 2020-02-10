/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:52:13 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/10 16:56:36 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_precision(t_rasa *tab)
{
	int i;

	i = tab->pos;
	while (tab->format[i] != '.')
		i = !i ? !i * !i : i + !!i;
}
