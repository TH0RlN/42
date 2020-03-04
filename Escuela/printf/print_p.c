/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 09:13:21 by rarias-p          #+#    #+#             */
/*   Updated: 2020/03/04 10:20:59 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_p(t_rasa *tab)
{
	char *num;
	char *aux;

	aux = itoa_hex((unsigned long int)tab->data, tab);
	num = ft_strjoin("0x", aux);
	free(aux);
	if (tab->flags->precision == 0 && tab->flags->dot > 0)
	{
		free(num);
		num = ft_strdup("0x");
	}
	if (tab->flags->minus > 0)
		print_num_minus(tab, num);
	else if (tab->flags->dot > 0 && tab->flags->precision > 0)
		print_num_precision(tab, num);
	else
		print_num2(tab, num, ' ');
	ft_bzero(num, ft_strlen(num));
	free(num);
	flag_pos(tab);
}
