/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:42:49 by rarias-p          #+#    #+#             */
/*   Updated: 2021/02/24 18:38:18 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		texture_err2(t_data *data, int fd)
{
	if (0 > (fd = open(data->text_so, O_RDONLY)) ||
	!(ft_strnstr(data->text_so, ".xpm", ft_strlen(data->text_so))))
		return (1);
	else
		close(fd);
	if (0 > (fd = open(data->text_sp, O_RDONLY)) ||
	!(ft_strnstr(data->text_sp, ".xpm", ft_strlen(data->text_sp))))
		return (1);
	else
		close(fd);
	if (0 > (fd = open(data->text_we, O_RDONLY)) ||
	!(ft_strnstr(data->text_we, ".xpm", ft_strlen(data->text_we))))
		return (1);
	else
		close(fd);
	return (0);
}

int		texture_err(t_data *data)
{
	int fd;

	if (!(data->text_ea) || !(data->text_no) || !(data->text_so) ||
		!(data->text_sp) || !(data->text_we) || !(data->text_sp))
		return (1);
	if (0 > (fd = open(data->text_ea, O_RDONLY)) ||
	!(ft_strnstr(data->text_ea, ".xpm", ft_strlen(data->text_ea))))
		return (1);
	else
	{
		close(fd);
		return (0);
	}
	if (0 > (fd = open(data->text_no, O_RDONLY)) ||
	!(ft_strnstr(data->text_no, ".xpm", ft_strlen(data->text_no))))
		return (1);
	else
	{
		close(fd);
		return (0);
	}
	return (texture_err2(data, fd));
}

int		errors(t_data *data)
{
	if (texture_err(data))
	{
		data->errors->general++;
		data->errors->texture++;
	}
	return (data->errors->general > 0 ? 1 : 0);
}

void	low_res(t_data *data)
{
	write(1, "Error\nToo low resolution\n", 26);
	salida(data);
}
