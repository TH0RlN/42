/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:32:51 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/14 18:25:39 by rarias-p         ###   ########.fr       */
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
	tab->data = 0;
	tab->f_len = 0;
	init_flags(tab->flags);
}

void	init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->dot = 0;
	flags->astp = 0;
	flags->astw = 0;
	flags->precision = 0;
}

int		ft_printf(const char *format, ...)
{
	t_rasa	*tab;

	if (!(tab = malloc(sizeof(t_rasa))))
		return (-1);
	if (!(tab->flags = malloc(sizeof(t_flags))))
		return (-1);
	init(tab, (char *)format);
	va_start(tab->list, format);
	while (tab->format[tab->pos] != '\0')
	{
		if (tab->format[tab->pos] == '%')
			checker(tab);
		else
		{
			write(1, &tab->format[tab->pos], 1);
			tab->len++;
		}
		tab->pos++;
	}
	va_end(tab->list);
	free(tab);
	return (tab->len);
}

//int		main(void)
//{
//	void *p;
//
//	p = malloc(2);
//	printf("  -->>  %u\n", ft_printf("%%"));
//	printf("  -->>  %u\n", printf("%%"));
//	return (0);
//}
