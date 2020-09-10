/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:28:45 by rarias-p          #+#    #+#             */
/*   Updated: 2020/09/10 19:01:31 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	remove2(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < data->lines_map)
	{
		i = 0;
		while (data->order_map[i][j] != 0)
			if (data->order_map[i][j] == '2')
				data->order_map[i++][j++] = '0';
	}
}

void	copy_map(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->lines_map)
	{
		data->order_map[i] = malloc(sizeof(data->matrix_map[i]));
		data->order_map[i] = data->matrix_map[i];
		i++;
	}
}

void	check_map(t_data *data)
{
	copy_map(data);
	remove2(data);
	int i;
	i = 0;
	printf("\n\n");
	while (i < data->lines_map)
		printf("%s\n", data->order_map[i++]);
}
