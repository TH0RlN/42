/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiez-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:40:50 by cdiez-me          #+#    #+#             */
/*   Updated: 2019/10/13 21:57:12 by cdiez-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 4

int	print_error();
int	str_len(char *str);

int	check_char(int i, int j, char *tb, char *str)
{
	if (str[i] > '0' && str[i] < '5')
	{
		if (i < 30)
		{
			if (str[i + 1] == ' ')
				tb[j] = str[i];
			else
				return (print_error());
		}
		else
			tb[j] = str[i];
	}
	else
		return (print_error());
	return (0);
}

int	rows_translate(char *tb, int *row_p, int i)
{
	if (tb[i + 8] == '2' && tb[i + 12] == '2')
		row_p[i] = 0;
	else if (tb[i + 8] == '2' && tb[i + 12] == '1')
		row_p[i] = 1;
	else if (tb[i + 8] == '1' && tb[i + 4 * 3] == '2')
		row_p[i] = 2;
	else if (tb[i + 8] == '2' && tb[i + 4 * 3] == '3')
		row_p[i] = 3;
	else if (tb[i + 8] == '3' && tb[i + 4 * 3] == '2')
		row_p[i] = 4;
	else if (tb[i + 8] == '1' && tb[i + 4 * 3] == '3')
		row_p[i] = 5;
	else if (tb[i + 8] == '3' && tb[i + 4 * 3] == '1')
		row_p[i] = 6;
	else if (tb[i + 8] == '4' && tb[i + 4 * 3] == '1')
		row_p[i] = 7;
	else if (tb[i + 8] == '1' && tb[i + 12] == '4')
		row_p[i] = 8;
	else
		return (print_error());
	return (0);
}

int	cols_translate(char *tb, int *col_p, int i)
{
	if (tb[i] == '2' && tb[i + 4] == '2')
		col_p[i] = 0;
	else if (tb[i] == '2' && tb[i + 4] == '1')
		col_p[i] = 1;
	else if (tb[i] == '1' && tb[i + 4] == '2')
		col_p[i] = 2;
	else if (tb[i] == '2' && tb[i + 4] == '3')
		col_p[i] = 3;
	else if (tb[i] == '3' && tb[i + 4] == '2')
		col_p[i] = 4;
	else if (tb[i] == '1' && tb[i + 4] == '3')
		col_p[i] = 5;
	else if (tb[i] == '3' && tb[i + 4] == '1')
		col_p[i] = 6;
	else if (tb[i] == '4' && tb[i + 4] == '1')
		col_p[i] = 7;
	else if (tb[i] == '1' && tb[i + 4] == '4')
		col_p[i] = 8;
	else
		return (print_error());
	return (0);
}

int	data_read(int argc, char **argv, int *col_p, int *row_p)
{
	int		i;
	int		j;
	char	tb[4 * SIZE];

	if (argc != 2 || str_len(argv[1]) != 31)
		return (print_error());
	j = 0;
	i = 0;
	while (i < 32)
	{
		if (check_char(i, j, tb, argv[1]))
			return (1);
		i = i + 2;
		j++;
	}
	i = 0;
	while (i < SIZE)
	{
		if (cols_translate(tb, col_p, i) || rows_translate(tb, row_p, i))
			return (1);
		i++;
	}
	return (0);
}
