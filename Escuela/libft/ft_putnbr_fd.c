/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:49:15 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/20 13:19:49 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	m;
	long int	i;
	long int	j;

	m = n;
	i = 0;
	if (m >= 0)
		i = m;
	if (m < 0)
	{
		i = m * -1;
		ft_putchar_fd('-', fd);
	}
	if (i >= 10)
		ft_putnbr_fd(i / 10, fd);
	j = i % 10 + '0';
	write(fd, &j, 1);
}
