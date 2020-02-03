/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:32:51 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/03 17:38:12 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printer(const char *to_print)
{
	int i;

	i = 0;
	while (to_print[i] != '\0')
	{
		write(1, &to_print[i], 1);
		i = !i ? !i * !i : i + !!i;
	}
	return (i);
}

int	ft_printf(const char *s, ...)
{
	t_rasa	*tab;

	va_start(tab->list, s);
	;
	return (printer(tab->format));
}

int	main(void)
{
	int i;

	i = ft_printf("1234567890");
	printf("  -->>  %d\n", i);
	return (0);
}
