/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:52:34 by rarias-p          #+#    #+#             */
/*   Updated: 2019/10/17 19:51:45 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_pt4(char c)
{
	if (c == 28)
		write(1, "1c", 2);
	if (c == 29)
		write(1, "1d", 2);
	if (c == 30)
		write(1, "1e", 2);
	if (c == 31)
		write(1, "1f", 2);
	if (c == 127)
		write(1, "7f", 2);
}

void	ft_print_pt3(char c)
{
	if (c == 21)
		write(1, "15", 2);
	if (c == 22)
		write(1, "16", 2);
	if (c == 23)
		write(1, "17", 2);
	if (c == 24)
		write(1, "18", 2);
	if (c == 25)
		write(1, "19", 2);
	if (c == 26)
		write(1, "1a", 2);
	if (c == 27)
		write(1, "1b", 2);
	if (c > 28)
		ft_print_pt4(c);
}

void	ft_print_pt2(char c)
{
	if (c == 10)
		write(1, "0a", 2);
	if (c == 11)
		write(1, "0b", 2);
	if (c == 12)
		write(1, "0c", 2);
	if (c == 13)
		write(1, "0d", 2);
	if (c == 14)
		write(1, "0e", 2);
	if (c == 15)
		write(1, "0f", 2);
	if (c == 16)
		write(1, "10", 2);
	if (c == 17)
		write(1, "11", 2);
	if (c == 18)
		write(1, "12", 2);
	if (c == 19)
		write(1, "13", 2);
	if (c == 20)
		write(1, "14", 2);
	if (c > 20)
		ft_print_pt3(c);
}

void	ft_print_nonprint(char c)
{
	write(1, '\\', 1);
	if (c == 0)
		write(1, "00", 2);
	if (c == 1)
		write(1, "01", 2);
	if (c == 2)
		write(1, "02", 2);
	if (c == 3)
		write(1, "03", 2);
	if (c == 4)
		write(1, "04", 2);
	if (c == 5)
		write(1, "05", 2);
	if (c == 6)
		write(1, "06", 2);
	if (c == 7)
		write(1, "07", 2);
	if (c == 8)
		write(1, "08", 2);
	if (c == 9)
		write(1, "09", 2);
	if (c > 9)
		ft_print_pt2(c);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 0 && str[i] < 32) || str[i] == 127)
		{
			ft_print_nonprint(str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
