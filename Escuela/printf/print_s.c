/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:56:18 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/12 11:48:25 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_s_precision(t_rasa *tab, int len_prt, int i, char *s)
{
	int len_s;

	len_s = ft_strlen(s);
	while (s[i] != '\0' && i < tab->flags->precision)
	{
		write(1, &s[i++], 1);
		tab->len++;
		len_prt++;
	}
	return (len_prt);
}

void	print_s(t_rasa *tab)
{
	char	*s;
	int		len_s;
	int		len_prt;
	int		i;

	s = (char *)tab->data;
	len_s = ft_strlen(s);
	i = 0;
	len_prt = 0;
	while (len_s + len_prt < tab->flags->width)
	{
		write(1, " ", 1);
		len_prt++;
		tab->len++;
	}
	if (tab->flags->dot > 0)
		len_prt = print_s_precision(tab, len_prt, i, s);
	else
		while (s[i] != '\0')
		{
			write(1, &s[i++], 1);
			tab->len++;
		}
	flag_pos(tab);
}
