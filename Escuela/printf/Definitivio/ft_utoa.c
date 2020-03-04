/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:53:27 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/15 20:56:51 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*utoa_string(unsigned int n, char *s, int i)
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

char		*ft_utoa(unsigned int n)
{
	char			*s;
	unsigned int	i;
	unsigned int	n1;

	i = 0;
	n1 = (unsigned int)n;
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
	utoa_string(n, s, i);
	return (s);
}
