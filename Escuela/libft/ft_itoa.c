/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 10:34:56 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/18 18:44:29 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		number_len(long n)
{
	int len;

	len = 1;
	while ((n /= 10) > 0)
		len++;
	return (len);
}

char	*desmembrator(long n, char *cnumber, int len)
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

char	*little(long n)
{
	char	*littlen;

	littlen = malloc(sizeof(char) * 2);
	littlen[0] = n + '0';
	littlen[1] = '\0';
	return (littlen);
}

char	*ft_itoa(int n)
{
	int		negcheck;
	long	nn;
	char	*cnumber;
	char	*neg;

	nn = (long)n;
	neg = "-0";
	negcheck = 1;
	if (nn < 0)
	{
		negcheck *= -1;
		nn *= -1;
	}
	if (!(cnumber = malloc(number_len(nn) * sizeof(char))))
		return (0);
	if (n < 10)
		cnumber = little(nn);
	else
		cnumber = desmembrator(nn, cnumber, number_len(nn));
	if (negcheck < 0)
		cnumber = ft_strjoin(neg, cnumber);
	return (cnumber);
}
