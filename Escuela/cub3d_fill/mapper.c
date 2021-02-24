/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:04:14 by rarias-p          #+#    #+#             */
/*   Updated: 2021/02/24 20:16:27 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	string_to_matrix(t_data *data)
{
	int	i;
	int	j;
	int	k;

	data->matrix_map = malloc(data->lines_map * sizeof(char *));
	i = 0;
	j = 0;
	k = 0;
	while (j < data->lines_map)
	{
		k = 0;
		data->matrix_map[j] = malloc(btwsp(data, i) * sizeof(char));
		while (data->map[i] != '\n' && data->map[i] != '\0')
			data->matrix_map[j][k++] = data->map[i++];
		data->matrix_map[j][k++] = 0;
		i++;
		j++;
	}
}

void	mtrx_2_imtrx(t_data *data)
{
	int	i;
	int	j;

	data->int_map = malloc(data->lines_map * sizeof(int *));
	i = 0;
	while (i < data->lines_map)
	{
		j = -1;
		data->int_map[i] = malloc(ft_strlen(data->matrix_map[i]) * sizeof(int));
		while (data->matrix_map[i][++j] != '\0')
			data->int_map[i][j] = data->matrix_map[i][j] < 58 ?
			data->matrix_map[i][j] - 48 : 0;
		i++;
	}
}

void	mapper(t_data *data)
{
	data->lines_map = 1;
	data->map = ft_strjoin(data->line, "\n");
	while (get_next_line(data->fd, &data->line))
	{
		data->map = ft_strjoin(data->map, ft_strjoin(data->line, "\n"));
		data->lines_map++;
	}
	data->map = ft_strjoin(data->map, data->line);
	data->lines_map++;
	string_to_matrix(data);
	mtrx_2_imtrx(data);
	rgb_to_hex(data);
}

void	no_map(void)
{
	write(1, "Error\nBad file formating\n\tInvalid map\n", 39);
	exit(0);
}
