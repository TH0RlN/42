/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:06:14 by edramire          #+#    #+#             */
/*   Updated: 2019/10/13 21:39:23 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		quick_solver(int *row, int *col, int *row_p, int *col_p);
void	ft_print_array(int *arr, int size);
int		data_read(int argc, char **argv, int *col_p, int *row_p);
int		print_error(void);

void	ini_data(int *col, int *row)
{
	int i;

	i = 0;
	while (i < 4)
	{
		col[i] = 0xffff;
		row[i] = 0xffff;
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		row_p[4];
	int		col_p[4];
	int		col[4];
	int		row[4];

	ini_data(col, row);
	if (data_read(argc, argv, col_p, row_p))
		return (0);
	if (quick_solver(row, col, row_p, col_p) < 0)
		print_error();
	else
		ft_print_array(row, 4);
	return (0);
}
