/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:28:45 by rarias-p          #+#    #+#             */
/*   Updated: 2020/11/20 20:05:31 by rarias-p         ###   ########.fr       */
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

void	remove2(t_data *data)
{
	int		i;
	int		j;
	int		check;

	i = 0;
	j = 0;
	check = 0;
	while (j < data->lines_map)
	{
		i = 0;
		while (data->fill_map[j][i] != '\0')
		{
			if (data->fill_map[j][i] == 'N' || data->fill_map[j][i] == 'S'
			|| data->fill_map[j][i] == 'E' || data->fill_map[j][i] == 'W')
			{
				if (check > 0)
				{
					printf("Error: \nToo many start possitions");
					return ;
				}
				else
				{
					data->init_pos->x = i;
					data->init_pos->y = j;
					data->fill_map[j][i] = '0';
					check++;
				}
			}
			else if(data->fill_map[j][i] == '2')
				data->fill_map[j][i] = '0';
			i++;
		}
		j++;
	}
}

void	check_map(t_data *data)
{
	int i;
	int check;
	
	i = 0;
	copy_map(data);
	remove2(data);
	check = start_fill(data);
	printf("\n\n");
	while (i < data->lines_map)
		printf("%s\n", data->fill_map[i++]);
	if (check == 1)	
		printf("\n\nMapa no válido\n");
	else
		printf("\n\nMapa válido\n");
}
