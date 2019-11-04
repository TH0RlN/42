/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:10:30 by rarias-p          #+#    #+#             */
/*   Updated: 2019/10/11 10:54:50 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printer(int a, int b)
{
	char fstc;
	char scdc;

	fstc = a / 10 + 48;
	scdc = a % 10 + 48;
	write(1, &fstc, 1);
	write(1, &scdc, 1);
	write(1, " ", 1);
	fstc = b / 10 + 48;
	scdc = b % 10 + 48;
	write(1, &fstc, 1);
	write(1, &scdc, 1);
	if (!(a == 98))
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int fstn;
	int scdn;

	fstn = 0;
	while (fstn <= 98)
	{
		scdn = fstn + 1;
		while (scdn <= 99)
		{
			printer(fstn, scdn);
			scdn++;
		}
		fstn++;
	}
}
