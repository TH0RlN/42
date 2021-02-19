/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 17:41:55 by rarias-p          #+#    #+#             */
/*   Updated: 2021/02/19 18:07:18 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int bmp_data(t_data *data)
{
	int h;
	int w;
	int color;
	
	h = 0;
	while (h < data->resy)
	{
		w = 0;
		while (w < data->resx)
		{
			color = data->
		}
		
	}
}

void	header_dib(t_data *data, int fd, int hex)
{
	hex = 0x00000028;
	write(fd, &hex, 4);
	hex = data->resx;
	write(fd, &hex, 4);
	hex = data->resy;
	write(fd, &hex, 4);
	hex = 0x0001;
	write(fd, &hex, 2);
	hex = 0x0020;
	write(fd, &hex, 2);
	hex = 0x00000000;
	write(fd, &hex, 4);
	hex = data->resy * data->resx * 4;
	write(fd, &hex, 4);
	hex = 0x00000B13;
	write(fd, &hex, 4);
	hex = 0x00000B13;
	write(fd, &hex, 4);
	hex = 0x00000000;
	write(fd, &hex, 4);
	hex = 0x00000000;
	write(fd, &hex, 4);
}

void	header_bmp(t_data *data, int fd)
{
	int hex;

	hex = 0x4D42;
	write(fd, &hex, 2);
	hex = data->resy * data->resx * 4 + 54;
	write(fd, &hex, 4);
	hex = 0x00000;
	write(fd, &hex, 2);
	hex = 0x0000;
	write(fd, &hex, 2);
	hex = 0x00000036;
	write(fd, &hex, 4);
	header_dib(data, fd, hex);
}

void	save_bmp(t_data *data)
{
	int		fd;

	drawer(data);
	if (!(fd = open("save.bmp", O_WRONLY | O_TRUNC | O_APPEND | O_CREAT,
	066)))
	{
		close(fd);
		go_dark(data);
	}
	headers(data, fd);
	if (bmp_data(data))
		go_dark(data);
	close(fd);
}
