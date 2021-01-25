/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 18:09:03 by rarias-p          #+#    #+#             */
/*   Updated: 2021/01/25 19:20:32 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	engine3(t_data *data, t_player *player, t_vector *ray, t_vector *plane)
{
	while(player->hit == 0)
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
}

void	engine2(t_data *data, t_player *player, t_vector *ray, t_vector *plane)
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
	engine3(data, player, ray, plane);
}

void	engine(t_data *data, t_player *player, t_vector *ray, t_vector *plane)
{
	int x;

	x = 0;
	while (x < data->resy)
	{
		data->camara_x = 2 * x / (double)data->resy - 1;
		ray->x = player->direction->x + plane->x * data->camara_x;
		ray->y = player->direction->y + plane->y * data->camara_x;
		player->int_pos_x = (int)player->position->x;
		player->int_pos_y = (int)player->position->y;
		player->delta_dist->x = fabs(1 / ray->x);
		player->delta_dist->y = fabs(1 / ray->x);
		player->hit = 0;
		engine2(data, player, ray, plane);
	}
}
