/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pminus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:50:07 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/10 08:59:15 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pminus(char *s, int num, t_rasa *tab)
{
	int		i;

	i = ft_strlen(s);
	tab->len += printer(s);
	while (i < num)
	{
		write(1, " ", 1);
		tab->len++;
		i = !i ? !i * !i : i + !!i;
	}
}
