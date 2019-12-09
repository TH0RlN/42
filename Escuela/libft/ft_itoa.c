/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 18:15:39 by abarral-          #+#    #+#             */
/*   Updated: 2019/11/25 18:20:49 by abarral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*itoa_string(int n, char *s, int i)
{
	s += i + 2;
	*--s = '\0';
	if (n < 0)
	{
		while (n != 0)
		{
			*--s = '0' + ((-n) % 10);
			n /= 10;
		}
		*--s = '-';
		return (s);
	}
	if (n >= 0)
	{
		*--s = '\0';
		while (n != 0)
		{
			*--s = '0' + (n % 10);
			n /= 10;
		}
	}
	return (s);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		n1;

	i = 0;
	n1 = (long int)n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	while (n1 != 0)
	{
		n1 /= 10;
		i++;
	}
	s = malloc(i + 2);
	if (s == NULL)
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	itoa_string(n, s, i);
	return (s);
}
