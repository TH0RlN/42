/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roto.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 18:30:02 by rarias-p          #+#    #+#             */
/*   Updated: 2021/02/03 17:15:17 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rot_rt(t_data *data)
{
	double	olddir;
	double	oldplane;

	olddir = data->player->direction->x;
	data->player->direction->x = data->player->direction->x * cos(ROT_SPEED) -
	data->player->direction->y * sin(ROT_SPEED);
	data->player->direction->y = olddir * sin(ROT_SPEED) +
	data->player->direction->y * cos(ROT_SPEED);
	oldplane = data->plane->x;
	data->plane->x = data->plane->x * cos(ROT_SPEED) -
	data->plane->y * sin(ROT_SPEED);
	data->plane->y = oldplane * sin(ROT_SPEED) +
	data->plane->y * cos(ROT_SPEED);
}

void	rot_lf(t_data *data)
{
	double	olddir;
	double	oldplane;

	olddir = data->player->direction->x;
	data->player->direction->x = data->player->direction->x * cos(-ROT_SPEED) -
	data->player->direction->y * sin(-ROT_SPEED);
	data->player->direction->y = olddir * sin(-ROT_SPEED) +
	data->player->direction->y * cos(-ROT_SPEED);
	oldplane = data->plane->x;
	data->plane->x = data->plane->x * cos(-ROT_SPEED) -
	data->plane->y * sin(-ROT_SPEED);
	data->plane->y = oldplane * sin(-ROT_SPEED) +
	data->plane->y * cos(-ROT_SPEED);
}
