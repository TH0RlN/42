/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 10:34:56 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/17 13:39:14 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	number_len(int n)
{
	int len;

	len = 1;
	while ((n /= 10) > 10)
		len++;
	len++;
	return (len);
}

char	*desmembrator(int n, char *cnumber, int len)
{
	int i;
	int divisor;

	divisor = 1;
	i = 0;
	while (i < len - 1)
	{
		divisor *= 10;
		i++;
	}
	i = 0;
	while (i < len)
	{
		cnumber[i] = (n / divisor) + '0';
		n %= divisor;
		divisor /= 10;
		i++;
	}
	cnumber[i] = '\0';
	return (cnumber);
}

char	*ft_itoa(int n)
{
	int		negcheck;
	char	*cnumber;
	char	neg[2];

	neg[0] = '-';
	neg[1] = '\0';
	negcheck = 1;
	if (n < 0)
	{
		negcheck *= -1;
		n *= -1;
	}
	if (!(cnumber = malloc(number_len(n) * sizeof(char))))
		return (0);
	cnumber = desmembrator(n, cnumber, number_len(n));
	if (negcheck < 0)
		cnumber = ft_strjoin(neg, cnumber);
	return (cnumber);
}
