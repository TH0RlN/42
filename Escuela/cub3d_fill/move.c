/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:31:43 by rarias-p          #+#    #+#             */
/*   Updated: 2021/02/03 18:42:04 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_fwd(t_data *data)
{
	if (data->int_map
	[(int)data->player->position->y]
	[(int)(data->player->position->x + data->player->direction->x * MOVE_SPEED)]
	== 0)
		data->player->position->x += data->player->direction->x * MOVE_SPEED;
	if (data->int_map
	[(int)(data->player->position->y + data->player->direction->y * MOVE_SPEED)]
	[(int)data->player->position->x]
	== 0)
		data->player->position->y += data->player->direction->y * MOVE_SPEED;
}

void	move_back(t_data *data)
{
	if (data->int_map
	[(int)data->player->position->y]
	[(int)(data->player->position->x - data->player->direction->x * MOVE_SPEED)]
	== 0)
		data->player->position->x -= data->player->direction->x * MOVE_SPEED;
	if (data->int_map
	[(int)(data->player->position->y - data->player->direction->y * MOVE_SPEED)]
	[(int)data->player->position->x]
	== 0)
		data->player->position->y -= data->player->direction->y * MOVE_SPEED;
}

void	move_rt(t_data *data)
{
	if (data->int_map
	[(int)data->player->position->y]
	[(int)(data->player->position->x - data->player->direction->x * MOVE_SPEED)]
	== 0)
		data->player->position->x += data->plane->x * MOVE_SPEED;
	if (data->int_map
	[(int)(data->player->position->y - data->player->direction->y * MOVE_SPEED)]
	[(int)data->player->position->x]
	== 0)
		data->player->position->y += data->plane->y * MOVE_SPEED;
}

void	move_lf(t_data *data)
{
	if (data->int_map
	[(int)data->player->position->y]
	[(int)(data->player->position->x - data->player->direction->x * MOVE_SPEED)]
	== 0)
		data->player->position->x -= data->plane->x * MOVE_SPEED;
	if (data->int_map
	[(int)(data->player->position->y - data->player->direction->y * MOVE_SPEED)]
	[(int)data->player->position->x]
	== 0)
		data->player->position->y -= data->plane->y * MOVE_SPEED;
}
