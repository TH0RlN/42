/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:13:43 by abarral-          #+#    #+#             */
/*   Updated: 2019/11/24 12:25:09 by abarral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long int	n2;
	char		c;

	n2 = (long int)n;
	if (n2 < 0)
	{
		n2 = -n2;
		write(fd, "-", 1);
	}
	if (n2 > 9)
		ft_putnbr_fd(n2 / 10, fd);
	c = (n2 % 10) + '0';
	write(fd, &c, 1);
}