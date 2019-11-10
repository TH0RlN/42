/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:07:48 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/10 17:45:24 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int i;
	int negcheck;
	int a;

	i = 0;
	a = 0;
	negcheck = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		negcheck *= -1;
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = a * 10 + (str[i] - '0');
		i++;
	}
	return (a * negcheck);
}
