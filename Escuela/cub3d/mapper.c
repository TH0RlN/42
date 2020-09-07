/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:04:14 by rarias-p          #+#    #+#             */
/*   Updated: 2020/09/07 20:41:12 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mapper(t_data *data)
{
	int i;
	int	j;
	int	lines;

	i = 0;
	j = 0;
	lines = 1;
	while (data->line[i] != '\0')
		data->map[j++] = data->line[i++];
	data->map[j++] = '\n';
	while (get_next_line(data->fd, &data->line))
	{
		i = 0;
		while (data->line[i] != '\0')
			data->map[j++] = data->line[i++];
		data->map[j++] = '\n';
	}
	i = 0;
	while (data->line[i] != '\0')
		data->map[j++] = data->line[i++];
	data->map[j++] = '\0';
}
