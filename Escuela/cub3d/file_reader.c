/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:56:51 by rarias-p          #+#    #+#             */
/*   Updated: 2020/09/08 17:04:07 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_data4(t_data *data, int i)
{
	if (data->line[i] == 'N' && data->line[i + 1] == 'O' &&
	data->line[i + 2] == ' ')
	{
		text(data, "NO", i);
		return (1);
	}
	else if (data->line[i] == 'S' && data->line[i + 1] == 'O' &&
			data->line[i + 2] == ' ')
	{
		text(data, "SO", i);
		return (1);
	}
	return (0);
}

int		get_data3(t_data *data, int i)
{
	if (data->line[i] == 'C' && data->line[i + 1] == ' ')
	{
		color(data, 'C', i);
		return (1);
	}
	else if (data->line[i] == '1' || data->line[i] == '0')
	{
		mapper(data);
		return (1);
	}
	else if (data->line[i] == 'W' && data->line[i + 1] == 'E' &&
	data->line[i + 2] == ' ')
	{
		text(data, "WE", i);
		return (1);
	}
	else
	{
		if (get_data4(data, i))
			return (1);
	}
	return (0);
}

int		get_data2(t_data *data, int i)
{
	if (data->line[i] == 'E' && data->line[i + 1] == 'A' &&
	data->line[i + 2] == ' ')
	{
		text(data, "EA", i);
		return (1);
	}
	else if (data->line[i] == 'S' && data->line[i + 1] == ' ')
	{
		text(data, "S", i);
		return (1);
	}
	else if (data->line[i] == 'F' && data->line[i + 1] == ' ')
	{
		color(data, 'F', i);
		return (1);
	}
	else
	{
		if (get_data3(data, i))
			return (1);
	}
	return (0);
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
			{
				resolution(data, i);
				break ;
			}
			else
			{
				if (get_data2(data, i))
					break ;
			}
			i++;
		}
	}
}

int		main(int argc, char const *argv[])
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->floor = malloc(sizeof(t_color));
	data->ceiling = malloc(sizeof(t_color));
	data->resx = 0;
	data->resy = 0;
	data->fd = open(argv[1], O_RDONLY);
	get_data(data);
	printf("Resolution:\n	X = %d\n	Y = %d\nTexture:\n	NO: %s\n	SO: %s\n	WE: %s\n	EA: %s\n	SP: %s\nColor:\n	C: %3d, %3d, %3d\n	F: %3d, %3d, %3d\nMap:\n%s\nNº lines: %d",
	data->resx, data->resy, data->text_no, data->text_so, data->text_we, data->text_ea, data->text_sp, data->ceiling->r, data->ceiling->g, data->ceiling->b, data->floor->r, data->floor->g, data->floor->b, data->map, data->lines_map);
	free(data);
}
