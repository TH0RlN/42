/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:50:10 by rarias-p          #+#    #+#             */
/*   Updated: 2021/02/16 17:40:07 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_sprites(t_data *data, int i)
{
	int temp;

	while (i < (data->n_of_2s - 1))
	{
		if (data->sprite_distance[i] < data->sprite_distance[i + 1])
		{
			temp = data->sprite_distance[i];
			data->sprite_distance[i] = data->sprite_distance[i + 1];
			data->sprite_distance[i + 1] = temp;
			temp = data->sprite_order[i];
			data->sprite_order[i] = data->sprite_order[i + 1];
			data->sprite_order[i + 1] = temp;
			temp = data->sprite_x[i];
			data->sprite_x[i] = data->sprite_x[i + 1];
			data->sprite_x[i + 1] = temp;
			temp = data->sprite_y[i];
			data->sprite_y[i] = data->sprite_y[i + 1];
			data->sprite_y[i + 1] = temp;
		}
		else
			i++;
	}
}

void	sprites4(t_data *data)
{
	int		stripe;
	int		y;

	stripe = data->draw_start_x - 1;
	while (++stripe < data->draw_end_x)
	{
		data->sprite_texx = (int)(256 * (stripe - (-data->sprite_width / 2 +
		data->sprite_screen_x)) * data->text_width / data->sprite_width) / 256;
		y = data->draw_start_y - 1;
		if (data->transform_y > 0 && stripe > 0 && stripe < data->resx
		/*&& data->transform_y < data->z_buffrer[stripe]*/)
			while (++y < data->draw_end_y)
			{
				data->d = y * 256 - data->resy * 128 + data->sprite_height
				* 128;
				data->sprite_texy = ((data->d * data->text_height)
				/ data->sprite_height) / 256;
				if (data->n_info4[data->text_width * data->sprite_texy
				+ data->sprite_texx] != 0)
					data->info_ptr[y * data->resx + stripe] = data->n_info4
					[data->text_width * data->sprite_texy + data->sprite_texx];
			}
	}
}

void	sprites3(t_data *data)
{
	data->sprite_height = abs((int)(data->resy / data->transform_y));
	data->draw_start_y = -data->sprite_height / 2 + data->resy / 2;
	if (data->draw_start_y < 0)
		data->draw_start_y = 0;
	data->draw_end_y = data->sprite_height / 2 + data->resy / 2;
	if (data->draw_end_y >= data->resy)
		data->draw_end_y = data->resy - 1;
	data->sprite_width = abs((int)(data->resy / data->transform_y)); //Está bien? resx transform_x
	data->draw_start_x = -data->sprite_width / 2 + data->sprite_screen_x;
	if (data->draw_start_x < 0)
		data->draw_start_x = 0;
	data->draw_end_x = data->sprite_width / 2 + data->sprite_screen_x;
	if (data->draw_end_x >= data->resx)
		data->draw_end_x = data->resx - 1;
	sprites4(data);
}

void	sprites2(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->n_of_2s)
	{
		data->sprite_pos_x = data->sprite_x[data->sprite_order[i]]
		- data->player->position->x;
		data->sprite_pos_y = data->sprite_y[data->sprite_order[i]]
		- data->player->position->y;
		data->invdet = 1.0 / (data->plane->x * data->player->direction->y
		- data->plane->y * data->player->direction->x);
		data->transform_x = data->invdet * (data->player->direction->y
		* data->sprite_pos_x - data->player->direction->x * data->sprite_pos_y);
		data->transform_y = (-data->plane->y * data->sprite_pos_x +
		data->plane->x * data->sprite_pos_y);
		data->sprite_screen_x = (int)((data->resx / 2) *
		(1 + data->transform_x / data->transform_y));
		sprites3(data);
	}
}

void	sprites(t_data *data)
{
	int i;

	data->sprite_order = malloc(sizeof(int *) * data->n_of_2s);
	data->sprite_distance = malloc(sizeof(int *) * data->n_of_2s);
	i = -1;
	while (++i < data->n_of_2s)
	{
		data->sprite_order[i] = i;
		data->sprite_distance[i] = ((data->player->position->x -
		data->sprite_x[i]) * (data->player->position->x -
		data->sprite_x[i]) + (data->player->position->y -
		data->sprite_y[i])
		* (data->player->position->y - data->sprite_y[i]));
	}
	sort_sprites(data, 0);
	sprites2(data);
}
