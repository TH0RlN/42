/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:49:32 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/14 09:26:22 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_digitcount(int n, int basesize)
{
	int		count;
	int		max;

	if (n < 0)
		n *= -1;
	max = basesize - 1;
	count = 1;
	while (n > max)
	{
		n = n / basesize;
		count++;
	}
	return (count);
}

static void	ft_putnbrbase(char *a, int n, int *ptr, char *base)
{
	int size;

	size = ft_strlen(base);
	if (n >= size)
		ft_putnbrbase(a, n / size, ptr, base);
	*ptr = *ptr + 1;
	a[*ptr] = base[n % size];
}

static char	*ft_edgecase(void)
{
	char	*a;

	a = malloc(sizeof(char) * 12);
	a[0] = '-';
	a[1] = '2';
	a[2] = '1';
	a[3] = '4';
	a[4] = '7';
	a[5] = '4';
	a[6] = '8';
	a[7] = '3';
	a[8] = '6';
	a[9] = '4';
	a[10] = '8';
	a[11] = '\0';
	return (a);
}

char		*ft_itoabase(int n, char *base)
{
	char	*a;
	int		digits;
	int		*ptr;
	int		i;

	if (n == -2147483648)
		return (ft_edgecase());
	i = -1;
	ptr = &i;
	digits = ft_digitcount(n, ft_strlen(base));
	i = -1 * (n >= 0) + 0;
	ptr = &i;
	a = malloc(sizeof(char) * (digits + 1 + 1 * (n < 0)));
	if (a == 0)
		return (0);
	a[digits + 1 * (n < 0)] = '\0';
	if (n < 0)
		a[0] = '-';
	n *= -1 * (n < 0) + 1 * (n >= 0);
	ft_putnbrbase(a, n, ptr, base);
	return (a);
}
