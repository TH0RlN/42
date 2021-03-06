/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archives.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:26:09 by rarias-p          #+#    #+#             */
/*   Updated: 2020/12/01 18:59:13 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	color_ceiling(t_data *data, int i)
{
	error_color(data, i);
	data->ceiling->r = ft_atoi(&data->line[i]);
	while (data->line[i] != ',' && data->line[i] != '\0')
		i++;
	data->ceiling->g = ft_atoi(&data->line[i + 1]);
	i++;
	while (data->line[i] != ',' && data->line[i] != '\0')
		i++;
	data->ceiling->b = ft_atoi(&data->line[i + 1]);
}

void	color(t_data *data, char dir, int i)
{
	while (data->line[i] != '\0')
	{
		if (data->line[i] > 47 && data->line[i] < 58)
		{
			if (dir == 'F')
			{
				error_color(data, i);
				data->floor->r = ft_atoi(&data->line[i]);
				while (data->line[i] != ',' && data->line[i] != '\0')
					i++;
				data->floor->g = ft_atoi(&data->line[i + 1]);
				i++;
				while (data->line[i] != ',' && data->line[i] != '\0')
					i++;
				data->floor->b = ft_atoi(&data->line[i + 1]);
				break ;
			}
			if (dir == 'C')
			{
				color_ceiling(data, i);
				break ;
			}
		}
		i++;
	}
}

void	resolution(t_data *data, int i)
{
	error_resolution(data, i + 1);
	while (data->line[i] != '\0')
	{
		if (data->line[i] == ' ')
			i++;
		else if (data->line[i] > 47 && data->line[i] < 58 && data->resx == 0)
		{
			data->resx = ft_atoi(&data->line[i]);
			while (data->line[i] > 47 && data->line[i] < 58 &&
			data->line[i] != '\0')
				i++;
		}
		else if (data->line[i] > 47 && data->line[i] < 58 && data->resy == 0)
		{
			data->resy = ft_atoi(&data->line[i]);
			while (data->line[i] > 47 && data->line[i] < 58 &&
			data->line[i] != '\0')
				i++;
		}
		else
			i++;
	}
}

void	text(t_data *data, char *dir, int i)
{
	while (data->line[i] != '\0')
	{
		if (data->line[i] == '.' && data->line[i + 1] == '/')
		{
			if (!(ft_strncmp(dir, "NO", 2)))
				data->text_no = ft_strdup(&data->line[i]);
			if (!(ft_strncmp(dir, "SO", 2)))
				data->text_so = ft_strdup(&data->line[i]);
			if (!(ft_strncmp(dir, "WE", 2)))
				data->text_we = ft_strdup(&data->line[i]);
			if (!(ft_strncmp(dir, "EA", 2)))
				data->text_ea = ft_strdup(&data->line[i]);
			if (!(ft_strncmp(dir, "S", 1)))
				data->text_sp = ft_strdup(&data->line[i]);
			break ;
		}
		i++;
	}
}
