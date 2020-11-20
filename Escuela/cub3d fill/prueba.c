/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:36:13 by rarias-p          #+#    #+#             */
/*   Updated: 2020/03/09 09:21:57 by rarias-p         ###   ########.fr       */
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
	int		color;
}				t_data;

int		out(void)
{
	printf("Bravo Six: Going Dark\n");
	exit(0);
	return (0);
}

int		deal_key(int key, t_data *d)
{
	printf("%i\n", key);
	if (key == 53)
		out();
	mlx_clear_window(d->mlx_ptr, d->win_ptr);
	if (key == 125 || key == 1)
		d->j += 5;
	else if (key == 124 || key == 2)
		d->i += 5;
	else if (key == 126 || key == 13)
		d->j -= 5;
	else if (key == 123 || key == 0)
		d->i -= 5;
	else if (key == 49)
		d->color = rand();
	mlx_pixel_put(d->mlx_ptr, d->win_ptr, d->i, d->j, d->color);
	mlx_pixel_put(d->mlx_ptr, d->win_ptr, d->i + 1, d->j, d->color);
	mlx_pixel_put(d->mlx_ptr, d->win_ptr, d->i, d->j + 1, d->color);
	mlx_pixel_put(d->mlx_ptr, d->win_ptr, d->i + 1, d->j + 1, d->color);
	return (0);
}

int		main(int argc, char const *argv[])
{
	t_data	d;

	d.i = 250;
	d.j = 250;
	d.mlx_ptr = mlx_init();
	d.win_ptr = mlx_new_window(d.mlx_ptr, 500, 500, "New Window");
	d.color = 0xffffff;
	mlx_hook(d.win_ptr, 17, 0, out, (void *)&d);
	mlx_key_hook(d.win_ptr, deal_key, (void *)&d);
	mlx_loop(d.mlx_ptr);
}
