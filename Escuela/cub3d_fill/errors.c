/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:42:49 by rarias-p          #+#    #+#             */
/*   Updated: 2020/11/30 19:05:47 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		texture_err2(t_data *data, int fd)
{
	if (0 > (fd = open(data->text_so, O_RDONLY)))
		return (1);
	else
	{
		close(fd);
		return (0);
	}
	if (0 > (fd = open(data->text_sp, O_RDONLY)))
		return (1);
	else
	{
		close(fd);
		return (0);
	}
	if (0 > (fd = open(data->text_we, O_RDONLY)))
		return (1);
	else
	{
		close(fd);
		return (0);
	}
}

int		texture_err(t_data *data)
{
	int fd;

	if (!(data->text_ea) || !(data->text_no) || !(data->text_so) ||
		!(data->text_sp) || !(data->text_we) || !(data->text_sp))
		return (1);
	if (0 > (fd = open(data->text_ea, O_RDONLY)))
		return (1);
	else
	{
		close(fd);
		return (0);
	}
	if (0 > (fd = open(data->text_no, O_RDONLY)))
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
