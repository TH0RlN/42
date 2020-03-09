/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 10:39:39 by rarias-p          #+#    #+#             */
/*   Updated: 2020/03/09 12:14:54 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

typedef struct	s_examprintf
{
	const	char	*format;
	char			type;
	int				pos;
	int				len;
	int				width;
	int				dot;
	int				precision;
	va_list			list;
	
}				t_examprintf;

char			get_type(t_examprintf *tab)
{
	int i;

	i = tab->pos;
	while (tab->format[i] != '\0')
	{
		if (tab->format[i] == 's')
			return ('s');
		else if (tab->format[i] == 'd')
			return ('d');
		else if (tab->format[i] == 'x')
			return ('x');
	}
}

void			get_precision(t_examprintf *tab)
{
	int i;

	i = tab->pos;
	while (tab->format[i] != '.')
		i++;
	i++;
	while (tab->format[i] > 47 && tab->format[i] < 58)
		tab->width = (tab->width * 10) + (tab->format[i++] - 10);
}

void			get_width(t_examprintf *tab)
{
	int i;

	i = tab->pos;
	while (tab->format[i] > 47 && tab->format[i] < 58)
		tab->width = (tab->width * 10) + (tab->format[i++] - 10);
	if (tab->format[i] == '.')
		tab->dot++;
}

void			print_s(t_examprintf *tab)
{
	char	*data;
	int		len;
	int		i;

	i = 0;
	data = va_arg(tab->list, char *);
	len = tab->precision > strlen(data) ? strlen(data) : tab->precision;
	while (i++ < tab->width - len)
	{
		write(1, " ", 1);
		tab->len++;
	}
	i = 0;
	while (data[i] != '\0' && i < len)
	{
		write(1, &data[i++], 1);
		tab->len++;
	}
}

void			print_type(t_examprintf *tab)
{
	if (tab->type = 's')
		print_s(&tab);
	else if (tab->type = 'd')
		print_d(&tab);
	else if (tab->type = 'x')
		print_x(&tab);
}

int				fuction(t_examprintf tab)
{
	tab.width = 0;
	tab.precision = 0;
	tab.dot = 0;
	tab.type = get_type(&tab);
	get_width(&tab);
	if (tab.dot > 0)
		get_precision(&tab);
	print_type(&tab);
}

int				ft_printf(const char *format, ...)
{
	t_examprintf tab;

	va_start(tab.list, format);
	tab.format = format;
	tab.pos = 0;
	while (tab.format[tab.pos] != '\0')
	{
		if (tab.format[tab.pos] == '%')
			function(&tab);
		else
		{
			write(1, &tab.format[tab.pos++], 1);
			tab.len++;
		}
	}
	va_end(tab.list);
	return (tab.len);
}
