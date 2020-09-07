/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:56:51 by rarias-p          #+#    #+#             */
/*   Updated: 2020/09/07 18:23:29 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	color(t_data *data, char dir, int i)
{
	while (data->line[i] != '\0')
	{
		if (data->line[i] > 47 && data->line[i] < 58)
		{
			if (dir == 'F')
			{
				data->floor->r = atoi(&data->line[i]);
				while (data->line[i] != ',')
					i++;
				data->floor->g = atoi(&data->line[++i]);
				while (data->line[i] != ',')
					i++;
				data->floor->g = atoi(&data->line[++i]);
			}
			if (dir == 'C')
			{
				data->ceiling->r = atoi(&data->line[i]);
				while (data->line[i] != ',')
					i++;
				data->ceiling->g = atoi(&data->line[++i]);
				while (data->line[i] != ',')
					i++;
				data->ceiling->g = atoi(&data->line[++i]);
			}
		}
		i++;
	}
}

void	resolution(t_data *data, int i)
{
	while (data->line[i] != '\0')
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
			data->resy = atoi(&data->line[i]);
			while (data->line[i] > 47 && data->line[i] < 58)
				i++;
		}
		else
			i++;
	}
}

void	text(t_data *data, char *dir, int i)
{
	while (data->line[i] != '\0')
	{
		if (data->line[i] == '.' && data->line[i + 1] == '/')
		{
			if (!(ft_strncmp(dir, "NO", 2)))
				data->text_no = &data->line[i];
			if (!(ft_strncmp(dir, "SO", 2)))
				data->text_so = &data->line[i];
			if (!(ft_strncmp(dir, "WE", 2)))
				data->text_we = &data->line[i];
			if (!(ft_strncmp(dir, "EA", 2)))
				data->text_ea = &data->line[i];
			if (!(ft_strncmp(dir, "S", 1)))
				data->text_sp = &data->line[i];
			break ;
		}
		i++;
	}
}

void	get_data2(t_data *data, int i)
{
	if (data->line[i] == 'E' && data->line[i + 1] == 'A' &&
	data->line[i + 2] == ' ')
		text(data, "EA", i);
	else if (data->line[i] == 'S' && data->line[i + 1] == ' ')
		text(data, "S", i);
	else if (data->line[i] == 'F' && data->line[i + 1] == ' ')
		color(data, 'F', i);
	else if (data->line[i] == 'C' && data->line[i + 1] == ' ')
		color(data, 'C', i);
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
			else if (data->line[i] == 'S' && data->line[i + 1] == 'O' &&
			data->line[i + 2] == ' ')
				text(data, "SO", i);
			else if (data->line[i] == 'W' && data->line[i + 1] == 'E' &&
			data->line[i + 2] == ' ')
				text(data, "WE", i);
			else if (data->line[i] == 'N' && data->line[i + 1] == 'O' &&
			data->line[i + 2] == ' ')
				text(data, "NO", i);
			else
				get_data2(data, i);
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
	printf("Resolution:\n	X = %d\n	Y = %d\nTexture:\n	NO: %s\n	SO: %s\n	WE: %s\n	EA: %s\n	SP: %s\nColor:\n	C: %d, %d, %d\n	F: %d, %d, %d",
	data->resx, data->resy, data->text_no, data->text_so, data->text_we, data->text_ea, data->text_sp, data->ceiling->r, data->ceiling->g, data->ceiling->b, data->floor->r, data->floor->g, data->floor->b);
	free(data);
}
