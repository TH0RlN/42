/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 19:25:52 by rarias-p          #+#    #+#             */
/*   Updated: 2021/02/23 19:40:08 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rgb_to_hex(t_data *data)
{
	data->ceiling_color = data->ceiling->r * pow(16, 4)
	+ data->ceiling->g * pow(16, 2) + data->ceiling->b;
	data->floor_color = data->floor->r * pow(16, 4)
	+ data->floor->g * pow(16, 2) + data->floor->b;
}

int		btwsp(t_data *data, int i)
{
	int		chars;

	chars = 0;
	while (data->map[i] != '\n' && data->map[i++] != '\0')
		chars++;
	return (chars + 2);
}

int		salida(t_data *data)
{
	go_dark(data);
	exit(EXIT_SUCCESS);
}

void	copy_map(t_data *data)
{
	int		i;

	i = 0;
	if (data->lines_map >= 0)
	{
		if (data->lines_map == 0)
			data->lines_map = 1;
		data->fill_map = malloc(sizeof(char *) * data->lines_map);
	}
	while (i < data->lines_map)
	{
		if (data->matrix_map)
			data->fill_map[i] = ft_strdup(data->matrix_map[i]);
		i++;
	}
}

void	save_2s(t_data *data, int n_of_2s)
{
	int	i;
	int	j;
	int k;

	j = 0;
	k = 0;
	data->sprite_x = malloc(sizeof(int *) * n_of_2s);
	data->sprite_y = malloc(sizeof(int *) * n_of_2s);
	while (j < data->lines_map && k < n_of_2s)
	{
		i = 0;
		while (data->matrix_map[j][i] != '\0' && k < n_of_2s)
		{
			if (data->matrix_map[j][i] == '2')
			{
				data->sprite_x[k] = i;
				data->sprite_y[k++] = j;
			}
			i++;
		}
		j++;
	}
}
