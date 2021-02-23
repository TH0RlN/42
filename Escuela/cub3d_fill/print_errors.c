/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:06:01 by rarias-p          #+#    #+#             */
/*   Updated: 2021/02/23 19:05:14 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_errors(t_data *data)
{
	write(1, "Error\n", 7);
	write(1, "Bad file formating\n", 20);
	if (data->errors->map)
		write(1, "\tInvalid map\n", 14);
	if (data->errors->colors)
		write(1, "\tInvalid colors\n", 17);
	if (data->errors->texture)
		write(1, "\tInvalid texture\n", 18);
	if (data->errors->resolution)
		write(1, "\tInvalid resolution\n", 21);
	exit(0);
}

void	arg_error(t_data *data)
{
	data->counter = 0;
	write(1, "Error\n", 7);
	write(1, "Not a valid flag\n", 18);
	exit(0);
}
