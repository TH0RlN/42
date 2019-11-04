/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:06:12 by rarias-p          #+#    #+#             */
/*   Updated: 2019/10/07 13:27:18 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	descartes(char q, char w, char e)
{
	char esp;
	char comma;

	esp = ' ';
	comma = ',';
	if (q < w && q < e && w < e)
	{
		write(1, &q, 1);
		write(1, &w, 1);
		write(1, &e, 1);
		if (q == '7' && w == '8' && e == '9')
		{
		}
		else
		{
			write(1, &comma, 1);
			write(1, &esp, 1);
		}
	}
}

void	ft_print_comb(void)
{
	char i;
	char u;
	char t;

	i = '0';
	while (i <= '9')
	{
		t = '0';
		while (t <= '9')
		{
			u = '0';
			while (u <= '9')
			{
				descartes(i, t, u);
				u++;
			}
			t++;
		}
		i++;
	}
}
