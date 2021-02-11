/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 15:46:34 by rarias-p          #+#    #+#             */
/*   Updated: 2021/02/08 17:03:50 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		array_image(t_data *data)
{
	data->texture = malloc(5 * sizeof(int *));
	data->texture[0] = data->n_info0;
	data->texture[1] = data->n_info1;
	data->texture[2] = data->n_info2;
	data->texture[3] = data->n_info3;
	//data->texture[4] = data->n_info4;
}

void	load_images(t_data *data)
{
	int		width;
	int		height;

	width = 64;
	height = 64;
	data->n_text0 = mlx_xpm_file_to_image(data->mlx_ptr, data->text_no,
	&width, &height);
	data->n_text1 = mlx_xpm_file_to_image(data->mlx_ptr, data->text_so,
	&width, &height);
	data->n_text2 = mlx_xpm_file_to_image(data->mlx_ptr, data->text_we,
	&width, &height);
	data->n_text3 = mlx_xpm_file_to_image(data->mlx_ptr, data->text_ea,
	&width, &height);
	//data->n_text4 = mlx_xpm_file_to_image(data->mlx_ptr, data->text_sp,
	//&width, &height);
	data->n_info0 = (int *)mlx_get_data_addr(data->n_text0, &data->bpp,
	&data->ls, &data->endian);
	data->n_info1 = (int *)mlx_get_data_addr(data->n_text1, &data->bpp,
	&data->ls, &data->endian);
	data->n_info2 = (int *)mlx_get_data_addr(data->n_text2, &data->bpp,
	&data->ls, &data->endian);
	data->n_info3 = (int *)mlx_get_data_addr(data->n_text3, &data->bpp,
	&data->ls, &data->endian);
	//data->n_info4 = (int *)mlx_get_data_addr(data->n_text4, &data->bpp,
	//&data->ls, &data->endian);
}

void	choose_text(t_data *data, int y)
{
	if (data->player->side == 1 && data->player->int_pos_y >
	data->player->position->y)
		data->info_ptr[y * data->resx + data->x] =
		data->n_info1[data->text_height * data->tex_y + data->tex_x];
	else if (data->player->side == 1 && data->player->int_pos_y <
	data->player->position->y)
		data->info_ptr[y * data->resx + data->x] =
		data->n_info0[data->text_height * data->tex_y + data->tex_x];
	else if (data->player->side == 0 && data->player->int_pos_x >
	data->player->position->x)
		data->info_ptr[y * data->resx + data->x] =
		data->n_info3[data->text_height * data->tex_y + data->tex_x];
	else
		data->info_ptr[y * data->resx + data->x] =
		data->n_info2[data->text_height * data->tex_y + data->tex_x];
}

void	draw_text2(t_data *data)
{
	int y;

	y = data->draw_start;
	while (y < data->draw_end)
	{
		data->tex_y = (int)data->tex_pos & (data->text_height - 1);
		data->tex_pos += data->step;
		choose_text(data, y);
		y++;
	}
}

void	draw_text(t_data *data)
{
	data->text_width = 64;
	data->text_height = 64;
	if (data->player->side == 0)
		data->wall_x = data->player->position->y + data->player->perp_wall_dist
		* data->ray->y;
	else
		data->wall_x = data->player->position->x + data->player->perp_wall_dist
		* data->ray->x;
	data->wall_x -= floor(data->wall_x);
	data->tex_x = (int)(data->wall_x * (double)(data->text_width));
	if (data->player->side == 0 && data->ray->x > 0)
		data->tex_x = data->text_width - data->tex_x - 1;
	if (data->player->side == 1 && data->ray->y < 0)
		data->tex_x = data->text_width - data->tex_x - 1;
	data->step = 1.0 * data->text_height / data->player->line_height;
	data->tex_pos = (data->draw_start - data->resy / 2 +
	data->player->line_height / 2) * data->step;
	draw_text2(data);
}
