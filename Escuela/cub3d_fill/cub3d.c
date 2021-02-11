/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:45:40 by rarias-p          #+#    #+#             */
/*   Updated: 2021/02/10 16:53:21 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_data *data)
{
	data->init_pos = malloc(sizeof(t_vector));
	data->ceiling = malloc(sizeof(t_color));
	data->errors = malloc(sizeof(t_errors));
	data->floor = malloc(sizeof(t_color));
	data->keys = malloc(sizeof(t_keys));
	data->ray = malloc(sizeof(t_vector));
	data->plane = malloc(sizeof(t_vector));
	data->player = malloc(sizeof(t_player));
	data->player->position = malloc(sizeof(t_vector));
	data->player->side_dist = malloc(sizeof(t_vector));
	data->player->direction = malloc(sizeof(t_vector));
	data->player->delta_dist = malloc(sizeof(t_vector));
	data->player->line_height = 0;
	data->plane->x = 0;
	data->plane->y = 0;
	data->check = 0;
	data->resx = 0;
	data->counter = 0;
	data->resy = 0;
	data->errors->map = 0;
	data->errors->colors = 0;
	data->errors->general = 0;
	data->errors->texture = 0;
	data->errors->resolution = 0;
	data->player->perp_wall_dist = 0;
	data->player->step_y = 0;
	data->player->step_x = 0;
	data->player->hit = 0;
	data->player->side = 0;
	data->player->int_pos_x = 0;
	data->player->int_pos_y = 0;
	data->draw_end = 0;
	data->draw_start = 0;
	data->n_of_2s = 0;
	data->keys->a = 0;
	data->keys->s = 0;
	data->keys->d = 0;
	data->keys->w = 0;
	data->keys->rt = 0;
	data->keys->lf = 0;
	data->keys->esc = 0;
}

void	go_dark(t_data *data)
{
	//ft_bzero(data->ray, sizeof(t_vector));
	//ft_bzero(data->plane, sizeof(t_vector));
	//ft_bzero(data->player->position, sizeof(t_vector));
	//ft_bzero(data->player->side_dist, sizeof(t_vector));
	//ft_bzero(data->player->direction, sizeof(t_vector));
	//ft_bzero(data->player->delta_dist, sizeof(t_vector));
	//ft_bzero(data->player, sizeof(t_player));
	//free(data->ray);
	//free(data->plane);
	//free(data->player->position);
	//free(data->player->side_dist);
	//free(data->player->direction);
	//free(data->player->delta_dist);
	//free(data->player);
	//free(data->init_pos);
	//free(data->line);
	//free(data->ceiling);
	//free(data->floor);
	//free(data->errors);
	//free(data->text_no);
	//free(data->text_so);
	//free(data->text_ea);
	//free(data->text_we);
	//free(data->text_sp);
	//free(data->map);
	//free(data->player->position);
	//free(data->player->direction);
	//free(data->player);
	//while (data->counter < data->lines_map)
	//	free(data->matrix_map[data->counter++]);
	//free(data->matrix_map);
	data->counter = 0;
	//while (data->counter < data->lines_map)
	//	free(data->fill_map[data->counter++]);
	//free(data->fill_map);
	//free(data);
	write(1, "GOING DARK \n", 13);
}

int		main(int argc, char const *argv[])
{
	t_data	*data;

	if (argc < 2 || argc > 3)
	{
		write(1, "Error\nNot enough arguments or too many arguments\n", 50);
		return (1);
	}
	data = malloc(sizeof(t_data));
	init(data);
	if (0 > (data->fd = open(argv[1], O_RDONLY)))
	{
		write(1, "Error\nCould not open file\n", 27);
		return (1);
	}
	get_data(data);
	check_map(data);
	if (!(errors(data)))
	////printf("Resolution:\n	X = %d\n	Y = %d\nTexture:\n	NO: %s\n	SO: %s\n	WE: %s\n	EA: %s\n	SP: %s\nColor:\n	C: %3d, %3d, %3d\n	F: %3d, %3d, %3d\n\nNº lines: %d\n\n\nErrors:\n\tMap: %d\n\tColors: %d\n\tTexture: %d\n\tResolution: %d\n\n\tTotal: %d",
	////data->resx, data->resy, data->text_no, data->text_so, data->text_we, data->text_ea, data->text_sp, data->ceiling->r, data->ceiling->g, data->ceiling->b, data->floor->r, data->floor->g, data->floor->b, data->lines_map, data->errors->map, data->errors->colors, data->errors->texture, data->errors->resolution, data->errors->general);
		main_loop(data);
	else
		print_errors(data);
	return (0);
}
