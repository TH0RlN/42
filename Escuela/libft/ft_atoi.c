/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:07:48 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/28 17:38:56 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int negcheck;
	int a;
	int sign;

	i = 0;
	a = 0;
	sign = 0;
	negcheck = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
	{
		i++;
		sign++;
	}
	if (str[i] == '-' && sign == 0)
	{
		negcheck *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		a = a * 10 + (str[i++] - '0');
	return (a * negcheck);
}
