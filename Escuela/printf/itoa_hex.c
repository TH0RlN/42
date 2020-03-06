/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 09:40:47 by rarias-p          #+#    #+#             */
/*   Updated: 2020/03/04 10:34:03 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		num_len(unsigned long int num)
{
	unsigned long int i;

	i = 1;
	while (num > 16)
	{
		num /= 16;
		i = !i ? !i * !i : i + !!i;
	}
	return (i);
}

char	*get_string(char *a, unsigned long int num, int *ptr, t_rasa *tab)
{
	char base[17];

	base[0] = '0';
	base[1] = '1';
	base[2] = '2';
	base[3] = '3';
	base[4] = '4';
	base[5] = '5';
	base[6] = '6';
	base[7] = '7';
	base[8] = '8';
	base[9] = '9';
	base[10] = tab->type == 'X' ? 'A' : 'a';
	base[11] = tab->type == 'X' ? 'B' : 'b';
	base[12] = tab->type == 'X' ? 'C' : 'c';
	base[13] = tab->type == 'X' ? 'D' : 'd';
	base[14] = tab->type == 'X' ? 'E' : 'e';
	base[15] = tab->type == 'X' ? 'F' : 'f';
	if (num >= 16)
		get_string(a, num / 16, ptr, tab);
	*ptr = *ptr + 1;
	a[*ptr] = base[num % 16];
	return (a);
}

char	*itoa_hex(unsigned long int num, t_rasa *tab)
{
	char	*s;
	int		i;
	int		*ptr;

	i = -1;
	ptr = &i;
	s = malloc(num_len(num));
	s = get_string(s, num, ptr, tab);
	return (s);
}
