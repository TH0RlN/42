/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_visual.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:41:52 by rarias-p          #+#    #+#             */
/*   Updated: 2020/12/12 18:21:00 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		salida(t_data *data)
{
	go_dark(data);
	exit(EXIT_SUCCESS);
}

void	start_direction(t_data *data)
{
	if (data->direction == 'N')
	{
		data->player->direction->x = 0;
		data->player->direction->y = -1;
	}
	if (data->direction == 'S')
	{
		data->player->direction->x = 0;
		data->player->direction->y = 1;
	}
	if (data->direction == 'E')
	{
		data->player->direction->x = 1;
		data->player->direction->y = 0;
	}
	if (data->direction == 'W')
	{
		data->player->direction->x = 0;
		data->player->direction->y = -1;
	}
	data->player->position = data->init_pos;
	printf("Posición inicial:\n\tX:%f\n\tY:%f\n", data->player->position->x, data->player->position->y);
}

void	main_loop(t_data *data)
{
	start_direction(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->resx, data->resy,
	"CUB3D");
	mlx_hook(data->win_ptr, 17, 0, salida, (void *)data);
	mlx_loop(data->mlx_ptr);
}
