/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_visual.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:41:52 by rarias-p          #+#    #+#             */
/*   Updated: 2020/12/11 17:26:54 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		salida(t_data *data)
{
	go_dark(data);
	exit(EXIT_SUCCESS);
}

void	init_loop(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->resx, data->resy,
	"CUB3D");
	mlx_hook(data->win_ptr, 17, 0, salida, (void *)data);
	mlx_loop(data->mlx_ptr);
}
