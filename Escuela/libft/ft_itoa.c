/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 10:34:56 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/15 12:12:40 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	number_len(int n)
{
	int len;

	len = 1;
	while (n /= 10 > 10)
		len++;
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	int nlen;
	int negcheck;

	if (n < 0)
	{
		negcheck *= -1;
		n *= -1;
	}
	nlen = number_len(n);
}
