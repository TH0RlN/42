/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:08:25 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/04 18:38:31 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pzero(int d, int num, t_rasa *tab)
{
	char	*s;
	int		i;

	s = ft_itoa(d);
	i = ft_strlen(s);
	while (i < num)
	{
		write(1, '0', 1);
		tab->len++;
		i = !i ? !i * !i : i + !!i;
	}
	tab->len += printer(s);
}
