/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pprecision_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 09:33:58 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/05 10:23:18 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pprecision_int(char *s, int num, t_rasa *tab)
{
	int i;

	i = ft_strlen(s);
	while (i < num)
	{
		write(1, '0', 1);
		tab->len++;
		i = !i ? !i * !i : i + !!i;
	}
	tab->len += printer(s);
}
