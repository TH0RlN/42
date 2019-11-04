/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:00:56 by rarias-p          #+#    #+#             */
/*   Updated: 2019/10/06 21:16:16 by egarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_bucle1(int x)
{
	int j;

	j = 1;
	while (j <= x)
	{
		if (j == 1)
		{
			ft_putchar('A');
		}
		else if (j > 1 && j < x)
		{
			ft_putchar('B');
		}
		else if (j == x)
		{
			ft_putchar('C');
		}
		j++;
	}
}

void	ft_bucle2(int x)
{
	int j;

	j = 1;
	while (j <= x)
	{
		if (j == 1 || j == x)
		{
			ft_putchar('B');
		}
		else if (j > 1 && j < x)
		{
			ft_putchar(' ');
		}
		j++;
	}
}

void	ft_bucle3(int x)
{
	int j;

	j = 1;
	while (j <= x)
	{
		if (j == 1)
		{
			ft_putchar('C');
		}
		else if (j > 1 && j < x)
		{
			ft_putchar('B');
		}
		else if (j == x)
		{
			ft_putchar('A');
		}
		j++;
	}
}

void	rush(int x, int y)
{
	int i;

	i = 1;
	while (i <= y && x > 0)
	{
		if (i == 1)
		{
			ft_bucle1(x);
		}
		else if (i > 1 && i < y)
		{
			ft_bucle2(x);
		}
		else if (i == y)
		{
			ft_bucle3(x);
		}
		ft_putchar('\n');
		i++;
	}
}
