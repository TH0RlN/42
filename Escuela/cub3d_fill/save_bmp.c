/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 17:41:55 by rarias-p          #+#    #+#             */
/*   Updated: 2021/02/22 17:38:41 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		bmp_data(t_data *data, int fd)
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
			color = data->info_ptr[data->resx * (data->resy - 1 - h) + w];
			if (write(fd, &color, 4) < 0)
				return (1);
			w++;
		}
		h++;
	}
	return (0);
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

	data->z_buffrer = malloc((sizeof(double)) * data->resx + 1);
	start_direction(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->resx, data->resy,
	"");
	drawer(data);
	if (!(fd = open("save.bmp", O_WRONLY | O_TRUNC | O_APPEND | O_CREAT,
	0444)))
	{
		close(fd);
		go_dark(data);
	}
	header_bmp(data, fd);
	if (bmp_data(data, fd))
		go_dark(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	close(fd);
}
