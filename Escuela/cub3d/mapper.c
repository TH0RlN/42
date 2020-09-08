/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:04:14 by rarias-p          #+#    #+#             */
/*   Updated: 2020/09/08 17:29:56 by rarias-p         ###   ########.fr       */
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
	while (data->map[i] != '\0')
	{
		while (data->map[i] != '\n')
			data->matrix_map[j][k++] = data->map[i++];
		j++;
	}
}

void	mapper(t_data *data)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	data->lines_map = 1;
	while (data->line[i] != '\0')
		data->map[j++] = data->line[i++];
	data->map[j++] = '\n';
	while (get_next_line(data->fd, &data->line))
	{
		i = 0;
		while (data->line[i] != '\0')
			data->map[j++] = data->line[i++];
		data->map[j++] = '\n';
		data->lines_map++;
	}
	i = 0;
	while (data->line[i] != '\0')
		data->map[j++] = data->line[i++];
	data->lines_map++;
	data->map[j++] = '\0';
	string_to_matrix(data);
}
