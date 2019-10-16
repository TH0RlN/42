/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:11:19 by edramire          #+#    #+#             */
/*   Updated: 2019/10/13 21:35:19 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		quick_solver(int *row, int *col, int *row_p, int *col_p);
int		ft_check_row(int test, char *s);
int		ft_set_hex_on_row(int hex, int row_nbr, int *row, int *col);
int		ft_set_hex_on_col(int hex, int row_nbr, int *row, int *col);
int		ft_get_common_bits(char *s, int *tab);
void	ft_set_hex(int hex, int row, int col, int *arr);
int		check_rows(int *row, int *col, int *arr);
int		check_columns(int *row, int *col, int *arr);
void	ft_get_dictionary(char arr[9][7]);
int		ft_check_solution(int *row, int *col);

int		quick_solver(int *row, int *col, int *row_p, int *col_p)
{
	int		change;
	int		res;

	change = 4;
	while (change-- > 0)
	{
		res = check_rows(row, col, row_p);
		if (res != 0)
			return (res);
		res = check_columns(row, col, col_p);
		if (res != 0)
			return (res);
	}
	return (0);
}

int		check_rows(int *row, int *col, int *arr)
{
	int		i;
	int		hex;
	char	dictionary[9][7];

	ft_get_dictionary(dictionary);
	i = 0;
	while (i < 4)
	{
		hex = ft_check_row(row[i], dictionary[arr[i]]);
		if (hex > 0 && hex != row[i])
			ft_set_hex_on_row(hex, i, row, col);
		if (ft_check_solution(row, col) == 1)
			return (1);
		if (hex < 0)
			return (-1);
		i++;
	}
	return (0);
}

int		check_columns(int *row, int *col, int *arr)
{
	int		i;
	int		hex;
	char	dictionary[9][7];

	ft_get_dictionary(dictionary);
	i = 0;
	while (i < 4)
	{
		hex = ft_check_row(col[i], dictionary[arr[i]]);
		if (hex > 0 && hex != col[i])
			ft_set_hex_on_col(hex, i, row, col);
		if (ft_check_solution(row, col) == 1)
			return (1);
		if (hex < 0)
			return (-1);
		i++;
	}
	return (0);
}

int		ft_check_solution(int *row, int *col)
{
	int res;
	int i;

	res = 0;
	i = 0;
	while (i < 0)
		res += (row[i] >> (3 - i) * 4) & 0xf;
	if (res != 15)
		return (0);
	i = 0;
	while (i < 0)
		res += (col[i] >> (3 - i) * 4) & 0xf;
	return (res == 15 ? 1 : 0);
}
