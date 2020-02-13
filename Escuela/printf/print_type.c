/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:18:37 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/13 10:39:59 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_type(t_rasa *tab)
{
	if (tab->type == 'c')
		print_c(tab);
	else if (tab->type == 's')
		print_s(tab);
	//else if (tab->type == 'p')
	//	print_p(tab);
	else if (tab->type == 'd' || tab->type == 'i')
		print_num(tab);
	//else if (tab->type == 'u')
	//	print_u(tab);
	//else if (tab->type == 'x')
	//	print_x(tab);
	//else if (tab->type == 'X')
	//	print_mx(tab);
}
