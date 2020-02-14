/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 09:40:47 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/14 10:20:07 by rarias-p         ###   ########.fr       */
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

char	*get_string(char *a, unsigned long int num, int *ptr)
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
	base[10] = 'a';
	base[11] = 'b';
	base[12] = 'c';
	base[13] = 'd';
	base[14] = 'e';
	base[15] = 'f';
	if (num >= 16)
		get_string(a, num / 16, ptr);
	*ptr = *ptr + 1;
	a[*ptr] = base[num % 16];
	return (a);
}

char	*itoa_hex(unsigned long int num)
{
	char	*s;
	int		i;
	int		*ptr;

	i = -1;
	ptr = &i;
	s = malloc(num_len(num));
	s = get_string(s, num, ptr);
	return (s);
}

//int		main(void)
//{
//	printf("%s", itoa_hex(15));
//}
