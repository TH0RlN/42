/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 11:27:28 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/15 17:00:01 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_pos(t_rasa *tab)
{
	while (tab->format[tab->pos] != '%' &&
			tab->format[tab->pos] != 'c' &&
			tab->format[tab->pos] != 's' &&
			tab->format[tab->pos] != 'p' &&
			tab->format[tab->pos] != 'd' &&
			tab->format[tab->pos] != 'i' &&
			tab->format[tab->pos] != 'u' &&
			tab->format[tab->pos] != 'x' &&
			tab->format[tab->pos] != 'X')
		tab->pos++;
}
