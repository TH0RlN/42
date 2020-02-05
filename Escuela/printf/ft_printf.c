/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:32:51 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/05 13:22:06 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printer(const char *to_print)
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

void	init(t_rasa *tab, char *format)
{
	tab->format = format;
	tab->pos = 0;
	tab->len = 0;
	tab->type = 0;
	tab->flags->minus = 0;
	tab->flags->zero = 0;
	tab->flags->width = 0;
	tab->flags->dot = 0;
	tab->flags->ast = 0;
	tab->flags->precision = 0;
}

int		ft_printf(const char *format, ...)
{
	t_rasa	*tab;

	if (!(tab = malloc(sizeof(t_rasa))))
		return (-1);
	init(tab, format);
	va_start(tab->list, format);
	tab->format = format;
	while (tab->format[tab->pos] != '\0')
	{
		if (tab->format[tab->pos] == '%')
		{
			if (!(tab->format[tab->pos + 1] == '%'))
			{
				va_arg(tab->list, void *);
				checker(tab);
			}
		}
		write(1, &tab->format[tab->pos], 1);
	}

	return (tab->len);
}

int		main(void)
{
	int i;

	i = ft_printf("1234567890  alo");
	printf("  -->>  %d\n", i);
	return (0);
}
