/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:28:45 by rarias-p          #+#    #+#             */
/*   Updated: 2021/02/24 20:17:43 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		fill(t_data *data, int i, int j)
{
	if (i < 0 || j < 0 || j > (data->lines_map - 1))
		return (1);
	else if (data->fill_map[j][i] == '0')
	{
		data->fill_map[j][i] = '.';
		if (fill(data, i + 1, j) || fill(data, i - 1, j) ||
			fill(data, i, j + 1) || fill(data, i, j - 1))
			return (1);
		else
			return (0);
	}
	else if (data->fill_map[j][i] == '1' || data->fill_map[j][i] == '.')
		return (0);
	else if (data->fill_map[j][i] == ' ' || data->fill_map[j][i] == '\0')
		return (1);
	return (1);
}

int		start_fill(t_data *data)
{
	int i;
	int j;

	i = data->init_pos->x;
	j = data->init_pos->y;
	return (fill(data, i, j));
}

void	initial_pos(t_data *data, int i, int j)
{
	data->is_pos++;
	data->init_pos->x = i;
	data->init_pos->y = j;
	if (data->fill_map[j][i] == 'N')
		data->direction = 'N';
	if (data->fill_map[j][i] == 'S')
		data->direction = 'S';
	if (data->fill_map[j][i] == 'E')
		data->direction = 'E';
	if (data->fill_map[j][i] == 'W')
		data->direction = 'W';
	data->fill_map[j][i] = '0';
}

void	remove2(t_data *data)
{
	int		i;
	int		j;

	j = -1;
	while (++j < data->lines_map)
	{
		i = -1;
		while (data->fill_map[j][++i] != '\0')
		{
			if (data->fill_map[j][i] == 'N' || data->fill_map[j][i] == 'S'
			|| data->fill_map[j][i] == 'E' || data->fill_map[j][i] == 'W')
			{
				if (data->check > 0)
					return ;
				else
					initial_pos(data, i, j);
			}
			else if (data->fill_map[j][i] == '2')
			{
				data->fill_map[j][i] = '0';
				data->n_of_2s++;
			}
		}
	}
	save_2s(data, data->n_of_2s);
}

void	check_map(t_data *data)
{
	int i;
	int check;

	i = 0;
	data->is_pos = 0;
	if (!data->map)
		no_map();
	copy_map(data);
	remove2(data);
	if ((check = start_fill(data)))
	{
		data->errors->map++;
		data->errors->general++;
	}
}
