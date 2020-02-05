/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pprecision_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 09:43:17 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/05 09:47:18 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pprecision_string(char *s, int num, t_rasa *tab)
{
	int i;

	i = 0;
	while (i < num && s[i] != '\0')
	{
		write(1, &s[i], 1);
		tab->len++;
		i = !i ? !i * !i : i + !!i;
	}
}
