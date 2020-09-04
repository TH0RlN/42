/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:56:51 by rarias-p          #+#    #+#             */
/*   Updated: 2020/09/04 20:02:17 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	resolution(t_data *data, int i)
{
	while (data->line[i] != '\n')
	{
		if (data->line[i] == ' ')
			i++;
		else if (data->line[i] > 47 && data->line[i] < 58 && data->resx == 0)
		{
			data->resx = atoi(&data->line[i]);
			while (data->line[i] > 47 && data->line[i] < 58)
				i++;
		}
		else if (data->line[i] > 47 && data->line[i] < 58 && data->resy == 0)
		{
			data->resx = atoi(&data->line[i]);
			while (data->line[i] > 47 && data->line[i] < 58)
				i++;
		}
		else
			i++;
	}
}

void	get_data(t_data *data)
{
	int i;

	while (get_next_line(data->fd, &data->line))
	{
		i = 0;
		while (data->line[i] != '\0')
		{
			if (data->line[i] == 'R' && data->line[i + 1] == ' ')
				resolution(data, i);
			i++;
		}
	}
}

int		main(int argc, char const *argv[])
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->resx = 0;
	data->resy = 0;
	data->fd = open(argv[1], O_RDONLY);
	get_data(data);
	printf("Resolution:\n	X = %d\n	Y = %d\n", data->resx, data->resy);
	free(data);
}
