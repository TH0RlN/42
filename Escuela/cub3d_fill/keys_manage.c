/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 18:27:34 by rarias-p          #+#    #+#             */
/*   Updated: 2021/01/29 19:06:22 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keys_press(int key, t_data *data)
{
	if (key == A_KEY)
		data->keys->a = 1;
	else if (key == S_KEY)
		data->keys->s = 1;
	else if (key == D_KEY)
		data->keys->d = 1;
	else if (key == W_KEY)
		data->keys->w = 1;
	else if (key == RT_KEY)
		data->keys->rt = 1;
	else if (key == LF_KEY)
		data->keys->lf = 1;
	else if (key == ESC_KEY)
		salida(data);
	return (0);
}

int	keys_released(int key, t_data *data)
{
	if (key == A_KEY)
		data->keys->a = 0;
	else if (key == S_KEY)
		data->keys->s = 0;
	else if (key == D_KEY)
		data->keys->d = 0;
	else if (key == W_KEY)
		data->keys->w = 0;
	else if (key == RT_KEY)
		data->keys->rt = 0;
	else if (key == LF_KEY)
		data->keys->lf = 0;
	return (0);
}
