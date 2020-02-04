/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pminus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:50:07 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/04 18:56:54 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pminus(int d, int num, t_rasa *tab)
{
	char	*s;
	int		i;

	s = ft_itoa(d);
	i = ft_strlen(s);
	tab->len += printer(s);
	while (i < num)
	{
		write(1, ' ', 1);
		tab->len++;
		i = !i ? !i * !i : i + !!i;
	}
}
