/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:28:45 by rarias-p          #+#    #+#             */
/*   Updated: 2020/09/11 19:33:50 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	change_to_zero(t_data *data, int i, int j)
{
	data->order_map[i][j] = '0';
	check_1s(data, i - 1, j);
	check_1s(data, i + 1, j);
	check_1s(data, i, j - 1);
	check_1s(data, i, j + 1);
}

void	check_1s(t_data *data, int i, int j)
{
	int ord;

	ord = 0;
	if (data->order_map[i][j] != '1')
		return ;
	if (i > 0)
		if (data->order_map[i - 1][j] == '1')
			ord++;
	if (i < data->lines_map)
		if (data->order_map[i + 1][j] == '1')
			ord++;
	if (j > 0)
		if (data->order_map[i][j - 1] == '1')
			ord++;
	if (data->order_map[i][j + 1] == '1')
		ord++;
	if (ord < 2)
		change_to_zero(data, i, j);
}

void	get_order(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < data->lines_map)
	{
		j = 0;
		while (data->order_map[i][j] != '\0')
		{
			if (data->order_map[i][j] == '1')
				check_1s(data, i, j);
			j++;
		}
		i++;
	}
}

void	remove2(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < data->lines_map)
	{
		j = 0;
		while (data->order_map[i][j] != '\0')
		{
			if (data->order_map[i][j] == 'N' || data->order_map[i][j] == 'S'
			|| data->order_map[i][j] == 'E' || data->order_map[i][j] == 'W'
			|| data->order_map[i][j] == '2')
				data->order_map[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	check_map(t_data *data)
{
	copy_map(data);
	remove2(data);
	get_order(data);
	int i;
	i = 0;
	printf("\n\n");
	while (i < data->lines_map)
		printf("%s\n", data->order_map[i++]);
}
