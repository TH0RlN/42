/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 18:09:03 by rarias-p          #+#    #+#             */
/*   Updated: 2021/01/27 18:32:04 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	engine4(t_data *data, t_player *player, t_vector *ray)
{
	int x;

	if (player->side == 0)
	{
		player->perp_wall_dist = (player->int_pos_x - player->position->x +
		(1 - player->step_x) / 2) / ray->x;
	}
	else
	{
		player->perp_wall_dist = (player->int_pos_y - player->position->y +
		(1 - player->step_y) / 2) / ray->y;
	}
	player->line_height = (int)(data->resy / player->perp_wall_dist);
	data->draw_start = -player->line_height / 2 + data->resy / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = player->line_height / 2 + data->resy / 2;
	if (data->draw_end >= data->resy)
		data->draw_end = data->resy - 1;
	x = 0;
	while (x <= data->draw_end)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->x, x, player->side == 1 ? 0x7777FF / 2 : 0x7777FF);
		x++;
	}
}

void	engine3(t_data *data, t_player *player, t_vector *ray)
{
	while (player->hit == 0)
	{
		if (player->side_dist->x < player->side_dist->y)
		{
			player->side_dist->x += player->delta_dist->x;
			player->int_pos_x += player->step_x;
			player->side = 0;
		}
		else
		{
			player->side_dist->y += player->delta_dist->y;
			player->int_pos_y += player->step_y;
			player->side = 1;
		}
		if (data->matrix_map[player->int_pos_x][player->int_pos_y] > 0)
			player->hit = 1;
	}
	engine4(data, player, ray);
}

void	engine2(t_data *data, t_player *player, t_vector *ray)
{
	if (ray->x < 0)
	{
		player->step_x = -1;
		player->side_dist->x = (player->position->x - player->int_pos_x) *
		player->delta_dist->x;
	}
	else
	{
		player->step_x = 1;
		player->side_dist->x = (-player->position->x + 1 + player->int_pos_x) *
		player->delta_dist->x;
	}
	if (ray->y < 0)
	{
		player->step_y = -1;
		player->side_dist->y = (player->position->y - player->int_pos_y) *
		player->delta_dist->y;
	}
	else
	{
		player->step_y = 1;
		player->side_dist->y = (-player->position->y + 1 + player->int_pos_y)
		* player->delta_dist->y;
	}
	engine3(data, player, ray);
}

void	engine(t_data *data, t_player *player, t_vector *ray, t_vector *plane)
{

	data->x = 0;
	while (data->x < data->resx)
	{
		data->camara_x = 2 * data->x / (double)data->resx - 1;
		ray->x = player->direction->x + plane->x * data->camara_x;
		ray->y = player->direction->y + plane->y * data->camara_x;
		player->int_pos_x = (int)player->position->x;
		player->int_pos_y = (int)player->position->y;
		player->delta_dist->x = fabs(1 / ray->x);
		player->delta_dist->y = fabs(1 / ray->x);
		player->hit = 0;
		engine2(data, player, ray);
		data->x++;
	}
}