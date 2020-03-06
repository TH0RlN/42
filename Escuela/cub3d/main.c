/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:36:13 by rarias-p          #+#    #+#             */
/*   Updated: 2020/03/06 20:10:25 by rarias-p         ###   ########.fr       */
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
	if (key == 53)
		exit(0);
	printf("%i\n", key);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (key == 125)
		data->j += 5;
	else if (key == 124)
		data->i += 5;
	else if (key == 126)
		data->j -= 5;
	else if (key == 123)
		data->i -= 5;
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->i, data->j, 0xffffff);
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->i + 1, data->j, 0xffffff);
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->i, data->j + 1, 0xffffff);
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->i + 1, data->j + 1, 0xffffff);
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

	data.i = 250;
	data.j = 250;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500, "New Window");
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
