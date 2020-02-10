/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwidth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 08:52:37 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/10 09:10:11 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pwidth(char *s, int num, t_rasa *tab)
{
	int	i;

	i = ft_strlen(s);
	while (i < num)
	{
		write(1, " ", 1);
		tab->len++;
		i = !i ? !i * !i : i + !!i;
	}
	tab->len += printer(s);
}
