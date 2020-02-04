/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:32:51 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/04 18:30:12 by rarias-p         ###   ########.fr       */
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

/*
**int		checker(const char *s, t_rasa *tab)
**{
**	int i;
**
**	i = 0;
**	while (s[i] != '\0')
**	{
**		if (s[i] == '%')
**			tab->type = type(s[i + 1]);
**		i = !i ? !i * !i : i + !!i;
**	}
**}
*/

int		ft_printf(const char *format, ...)
{
	t_rasa	*tab;

	va_start(tab->list, format);
	return (0);
}

int		main(void)
{
	int i;

	i = ft_printf("1234567890  alo");
	printf("  -->>  %d\n", i);
	return (0);
}
