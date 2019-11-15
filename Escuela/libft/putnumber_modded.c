/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnumber_modded.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 10:40:46 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/15 10:41:16 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

void	writer(int nb)
{
	char		c;
	long int	d;

	if (!(nb < 10))
	{
		d = 1;
		while (nb / d != 0)
		{
			d *= 10;
		}
		d /= 10;
		while (d >= 10)
		{
			c = nb / d + '0';
			nb = nb % d;
			write(1, &c, 1);
			d /= 10;
		}
	}
	c = nb + '0';
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb *= -1;
		}
		writer(nb);
	}
}
