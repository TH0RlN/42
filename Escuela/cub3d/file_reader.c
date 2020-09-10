/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:56:51 by rarias-p          #+#    #+#             */
/*   Updated: 2020/09/10 17:46:38 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_data4(t_data *data, int i)
{
	if (data->line[i] == 'N' && data->line[i + 1] == 'O' &&
	data->line[i + 2] == ' ')
	{
		text(data, "NO", i);
		return (1);
	}
	else if (data->line[i] == 'S' && data->line[i + 1] == 'O' &&
			data->line[i + 2] == ' ')
	{
		text(data, "SO", i);
		return (1);
	}
	return (0);
}

int		get_data3(t_data *data, int i)
{
	if (data->line[i] == 'C' && data->line[i + 1] == ' ')
	{
		color(data, 'C', i);
		return (1);
	}
	else if (data->line[i] == '1' || data->line[i] == '0')
	{
		mapper(data);
		return (1);
	}
	else if (data->line[i] == 'W' && data->line[i + 1] == 'E' &&
	data->line[i + 2] == ' ')
	{
		text(data, "WE", i);
		return (1);
	}
	else
	{
		if (get_data4(data, i))
			return (1);
	}
	return (0);
}

int		get_data2(t_data *data, int i)
{
	if (data->line[i] == 'E' && data->line[i + 1] == 'A' &&
	data->line[i + 2] == ' ')
	{
		text(data, "EA", i);
		return (1);
	}
	else if (data->line[i] == 'S' && data->line[i + 1] == ' ')
	{
		text(data, "S", i);
		return (1);
	}
	else if (data->line[i] == 'F' && data->line[i + 1] == ' ')
	{
		color(data, 'F', i);
		return (1);
	}
	else
	{
		if (get_data3(data, i))
			return (1);
	}
	return (0);
}

void	get_data(t_data *data)
{
	int i;

	while (get_next_line(data->fd, &data->line))
	{
		i = 0;
		while (data->line[i] != '\0')
		{
			if (data->line[i] == 'R' && data->line[i + 1] == ' ')
			{
				resolution(data, i);
				break ;
			}
			else
			{
				if (get_data2(data, i))
					break ;
			}
			i++;
		}
	}
}
