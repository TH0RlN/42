/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:51:57 by rarias-p          #+#    #+#             */
/*   Updated: 2020/12/09 16:44:51 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_color(t_data *data, int i)
{
	while (data->line[i] != '\0')
	{
		if (!((data->line[i] > 47 && data->line[i] < 58) ||
			data->line[i] == 32 || data->line[i] == 44))
		{
			data->errors->colors++;
			data->errors->general++;
		}
		i++;
	}
}

void	error_resolution(t_data *data, int i)
{
	while (data->line[i] != '\0')
	{
		if (!((data->line[i] > 47 && data->line[i] < 58) ||
			data->line[i] == 32))
		{
			data->errors->resolution++;
			data->errors->general++;
		}
		i++;
	}
}
