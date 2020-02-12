/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 11:27:28 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/12 09:39:27 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_pos(t_rasa *tab)
{
	while (tab->format[tab->pos] != tab->type)
		tab->pos++;
	tab->pos++;
}
