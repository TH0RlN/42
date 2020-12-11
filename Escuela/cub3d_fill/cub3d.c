/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:45:40 by rarias-p          #+#    #+#             */
/*   Updated: 2020/12/11 17:54:51 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_data *data)
{
	data->init_pos = malloc(sizeof(t_vector));
	data->ceiling = malloc(sizeof(t_color));
	data->errors = malloc(sizeof(t_errors));
	data->floor = malloc(sizeof(t_color));
	data->player = malloc(sizeof(t_player));
	data->player->position = malloc(sizeof(t_vector));
	data->player->direction = malloc(sizeof(t_vector));
	data->check = 0;
	data->resx = 0;
	data->counter = 0;
	data->resy = 0;
	data->errors->map = 0;
	data->errors->colors = 0;
	data->errors->general = 0;
	data->errors->texture = 0;
	data->errors->resolution = 0;
}

void	go_dark(t_data *data)
{
	free(data->init_pos);
	free(data->line);
	free(data->ceiling);
	free(data->floor);
	free(data->errors);
	free(data->text_no);
	free(data->text_so);
	free(data->text_ea);
	free(data->text_we);
	free(data->text_sp);
	free(data->map);
	free(data->player->position);
	free(data->player->direction);
	free(data->player);
	while (data->counter < data->lines_map)
		free(data->matrix_map[data->counter++]);
	free(data->matrix_map);
	data->counter = 0;
	while (data->counter < data->lines_map)
		free(data->fill_map[data->counter++]);
	free(data->fill_map);
	free(data);
}

int		main(int argc, char const *argv[])
{
	t_data	*data;

	if (argc < 2 || argc > 3)
	{
		printf("Error\nNot enough arguments or too many arguments\n");
		return (1);
	}
	data = malloc(sizeof(t_data));
	init(data);
	if (0 > (data->fd = open(argv[1], O_RDONLY)))
	{
		printf("Error\nCould not open file\n");
		return (1);
	}
	get_data(data);
	check_map(data);
	if (!(errors(data)))
	//printf("Resolution:\n	X = %d\n	Y = %d\nTexture:\n	NO: %s\n	SO: %s\n	WE: %s\n	EA: %s\n	SP: %s\nColor:\n	C: %3d, %3d, %3d\n	F: %3d, %3d, %3d\n\nNº lines: %d\n\n\nErrors:\n\tMap: %d\n\tColors: %d\n\tTexture: %d\n\tResolution: %d\n\n\tTotal: %d",
	//data->resx, data->resy, data->text_no, data->text_so, data->text_we, data->text_ea, data->text_sp, data->ceiling->r, data->ceiling->g, data->ceiling->b, data->floor->r, data->floor->g, data->floor->b, data->lines_map, data->errors->map, data->errors->colors, data->errors->texture, data->errors->resolution, data->errors->general);
		init_loop(data);
	return (0);
}
