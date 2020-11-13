/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:45:40 by rarias-p          #+#    #+#             */
/*   Updated: 2020/11/13 18:56:15 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_data *data)
{
	data->floor = malloc(sizeof(t_color));
	data->ceiling = malloc(sizeof(t_color));
	data->resx = 0;
	data->resy = 0;
}

int		main(int argc, char const *argv[])
{
	t_data	*data;

	if (argc < 2)
	{
		printf("Error\nNot enough arguments\n");
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
	//printf("Resolution:\n	X = %d\n	Y = %d\nTexture:\n	NO: %s\n	SO: %s\n	WE: %s\n	EA: %s\n	SP: %s\nColor:\n	C: %3d, %3d, %3d\n	F: %3d, %3d, %3d\nMap:\n%s\nNº lines: %d",
	//data->resx, data->resy, data->text_no, data->text_so, data->text_we, data->text_ea, data->text_sp, data->ceiling->r, data->ceiling->g, data->ceiling->b, data->floor->r, data->floor->g, data->floor->b, data->map, data->lines_map);
	free(data);
	return (0);
}
