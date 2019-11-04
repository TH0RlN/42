/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:16:48 by edramire          #+#    #+#             */
/*   Updated: 2019/10/13 21:41:36 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_array(int *arr, int size);
int		str_len(char *str);
int		print_error(void);
int		ft_get_common_bits(char *s, int *tab);

int		ft_get_common_bits(char *s, int *tab)
{
	int hex;

	hex = 0xffff;
	while (*s != '\0')
		hex &= *(tab + *s++ - 'A');
	return (hex);
}

void	ft_print_array(int *arr, int size)
{
	int		i;
	int		j;
	char	aux;

	i = 0;
	while (i < size)
	{
		j = size - 1;
		while (j >= 0)
		{
			aux = ((arr[i] >> (j * size)) & 0xf) + '0';
			if (aux == '8')
				aux = '4';
			else if (aux == '4')
				aux = '3';
			write(1, &aux, 1);
			if (j != 0)
				write(1, " ", 1);
			j--;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		str_len(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		print_error(void)
{
	write(1, "Error\n", 6);
	return (1);
}
