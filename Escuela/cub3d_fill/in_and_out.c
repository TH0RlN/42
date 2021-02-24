/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_and_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:54:00 by rarias-p          #+#    #+#             */
/*   Updated: 2021/02/24 18:38:39 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init2(t_data *data)
{
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
	init2(data);
}

void	go_dark2(t_data *data)
{
	free(data->matrix_map);
	free(data->map);
	free(data->player->delta_dist);
	free(data->player->direction);
	free(data->player->side_dist);
	free(data->player->position);
	free(data->player);
	free(data->plane);
	free(data->ray);
	free(data->keys);
	free(data->floor);
	free(data->errors);
	free(data->ceiling);
	free(data->init_pos);
	free(data);
}

void	go_dark(t_data *data)
{
	free(data->win_ptr);
	free(data->mlx_ptr);
	free(data->z_buffrer);
	data->counter = 0;
	while (data->counter < data->lines_map)
		free(data->fill_map[data->counter++]);
	free(data->fill_map);
	data->counter = 0;
	while (data->counter < data->lines_map)
		free(data->int_map[data->counter++]);
	free(data->int_map);
	data->counter = 0;
	while (data->counter < data->lines_map)
		free(data->matrix_map[data->counter++]);
	go_dark2(data);
}
