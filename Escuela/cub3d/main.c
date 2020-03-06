/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:36:13 by rarias-p          #+#    #+#             */
/*   Updated: 2020/03/06 17:53:47 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		i;
	int		j;
}				t_data;

int		deal_key(int key, t_data *data)
{
	int color;
	int a;
	int b;

	if (key == 53)
		exit(0);
	printf("%i\n", key);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	b = 0;
	a = 0;
	data->i = 0;
	data->j = 0;
	if (key == 36)
	{
		while (data->i < 500)
		{
			color = rand();
			b = 0;
			while (b++ < 25)
			{
				data->j = 0;
				while (data->j < 500)
				{
					a = 0;
					while (a++ < 25)
						mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->i, data->j++, color);
				}
				data->i++;
			}
		}
	}
	else
	{
		while (data->j < 500)
		{
			color = rand();
			b = 0;
			while (b++ < 25)
			{
				data->i = 0;
				while (data->i < 500)
				{
					a = 0;
					while (a++ < 25)
						mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->i++, data->j, color);
				}
				data->j++;
			}
		}
	}
	return (0);
}

int		out(void)
{
	exit(0);
	return (0);
}

int		main(int argc, char const *argv[])
{
	t_data	data;

	data.i = 0;
	data.j = 0;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500, "New Window");
	while (data.j < 500)
	{
		data.i = 0;
		while (data.i < 500)
		{
			mlx_pixel_put(data.mlx_ptr, data.win_ptr, data.i++, data.j, 0xffffff);
		}
		data.j++;
	}
	mlx_hook(data.win_ptr, 17, 0, out, (void *)&data);
	mlx_key_hook(data.win_ptr, deal_key, (void *)&data);
	mlx_loop(data.mlx_ptr);
}

//#include <mlx.h>
//
//typedef struct  s_vars {
//    void        *mlx;
//    void        *win;
//}               t_vars;
//
//int             close(int keycode, t_vars *vars)
//{
//    mlx_destroy_window(vars->mlx, vars->win);
//	exit(0);
//}
//
//int             main(void)
//{
//    t_vars      vars;
//
//    vars.mlx = mlx_init();
//    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
//    mlx_key_hook(vars.win, close, &vars);
//    mlx_loop(vars.mlx);
//}
