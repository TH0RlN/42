/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_visual.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:41:52 by rarias-p          #+#    #+#             */
/*   Updated: 2021/02/10 16:54:44 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		drawer(t_data *data)
{
	keys_change(data, data->keys);
	engine(data, data->player, data->ray, data->plane);
	return (0);
}

void	start_direction(t_data *data)
{
	if (data->direction == 'W')
	{
		data->player->direction->x = -1.0;
		data->player->direction->y = 0.0;
		data->plane->x = 0.0;
		data->plane->y = -0.66;
	}
	else if (data->direction == 'E')
	{
		data->player->direction->x = 1.0;
		data->player->direction->y = 0.0;
		data->plane->x = 0.0;
		data->plane->y = 0.66;
	}
	else if (data->direction == 'S')
	{
		data->player->direction->x = 0.0;
		data->player->direction->y = 1.0;
		data->plane->x = -0.66;
		data->plane->y = 0.0;
	}
	else if (data->direction == 'N')
	{
		data->player->direction->x = 0.0;
		data->player->direction->y = -1.0;
		data->plane->x = 0.66;
		data->plane->y = 0.0;
	}
	data->player->position->x = data->init_pos->x;
	data->player->position->y = data->init_pos->y;
	//printf("Posición inicial:\n\tX:%f\n\tY:%f\n", data->player->position->x, data->player->position->y);
}

void	main_loop(t_data *data)
{
	data->z_buffrer = malloc((sizeof(double)) * data->resx + 1);
	start_direction(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->resx, data->resy,
	"CUB3D");
	mlx_loop_hook(data->mlx_ptr, drawer, data);
	mlx_hook(data->win_ptr, 17, 0, salida, (void *)data);
	mlx_hook(data->win_ptr, 2, 0, keys_press, (void *)data);
	mlx_hook(data->win_ptr, 3, 0, keys_released, (void *)data);
	mlx_loop(data->mlx_ptr);
}
