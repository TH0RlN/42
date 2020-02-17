/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 09:13:21 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/17 12:18:15 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_p(t_rasa *tab)
{
	char *num;

	num = itoa_hex((unsigned long int)tab->data, tab);
	num = ft_strjoin("0x", num);
	if (tab->flags->minus > 0)
		print_num_minus(tab, num);
	else
		print_num2(tab, num, ' ');
	free(num);
	flag_pos(tab);
}
