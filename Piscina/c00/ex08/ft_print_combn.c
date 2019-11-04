/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:07:49 by rarias-p          #+#    #+#             */
/*   Updated: 2019/10/11 10:59:00 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int c)
{
	char a;

	if (c  > 0)
	{
		ft_putnbr(c / 10);
		a = c % 10 + '0';
		write(1, &a, 1);
	}
}

void	ft_print_combn(int n)
{
	if (n == 9)

	else if (n == 8)

	else if (n == 7)

	else if (n == 6)

	else if (n == 5)

	else if (n == 4)

	else if (n == 3)

	else if (n == 2)

	else if (n == 1)
}
