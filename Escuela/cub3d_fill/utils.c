/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 19:25:52 by rarias-p          #+#    #+#             */
/*   Updated: 2020/11/23 20:46:46 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		btwsp(t_data *data, int i)
{
	int		chars;

	chars = 0;
	while (data->map[i] != '\n' && data->map[i++] != '\0')
		chars++;
	return (chars + 2);
}

void	copy_map(t_data *data)
{
	int		i;

	i = 0;
	if (data->lines_map >= 0)
	{
		if (data->lines_map == 0)
			data->lines_map = 1;
		data->fill_map = malloc(sizeof(char *) * data->lines_map);
	}
	while (i < data->lines_map)
	{
		if (data->matrix_map)
			data->fill_map[i] = ft_strdup(data->matrix_map[i]);
		i++;
	}
}
