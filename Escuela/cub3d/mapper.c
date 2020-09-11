/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:04:14 by rarias-p          #+#    #+#             */
/*   Updated: 2020/09/10 20:18:41 by rarias-p         ###   ########.fr       */
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
		printf("%s\n", data->matrix_map[j]);
		i++;
		j++;
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
}
