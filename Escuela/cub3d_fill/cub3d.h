/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 17:22:45 by rarias-p          #+#    #+#             */
/*   Updated: 2021/02/23 19:40:50 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define W_KEY 13
# define RT_KEY 124
# define LF_KEY 123
# define UP_KEY 126
# define DW_KEY 125
# define ESC_KEY 53
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.085

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"

/*
** **************************************************************************
**									cub3d
** **************************************************************************
*/

typedef struct	s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef	struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_errors
{
	int			map;
	int			colors;
	int			texture;
	int			resolution;
	int			general;
}				t_errors;

typedef	struct	s_keys
{
	int			a;
	int			s;
	int			d;
	int			w;
	int			rt;
	int			lf;
	int			esc;
}				t_keys;

typedef struct	s_player
{
	t_vector	*position;
	t_vector	*direction;
	t_vector	*side_dist;
	t_vector	*delta_dist;
	double		perp_wall_dist;
	int			line_height;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			int_pos_x;
	int			int_pos_y;
}				t_player;

typedef	struct	s_data
{
	unsigned int	ceiling_color;
	unsigned int	floor_color;
	int				x;
	int				fd;
	int				resx;
	int				resy;
	int				check;
	int				counter;
	int				lines_map;
	int				draw_start;
	int				draw_end;
	int				draw_start_x;
	int				draw_end_x;
	int				draw_start_y;
	int				draw_end_y;
	int				**int_map;
	char			direction;
	char			*map;
	char			**matrix_map;
	char			**fill_map;
	char			*text_no;
	char			*text_so;
	char			*text_we;
	char			*text_ea;
	char			*text_sp;
	char			*line;
	int				*info_ptr;
	void			*img_ptr;
	void			*mlx_ptr;
	void			*win_ptr;
	int				*n_info0;
	int				*n_info1;
	int				*n_info2;
	int				*n_info3;
	int				*n_info4;
	int				**texture;
	int				*n_text0;
	int				*n_text1;
	int				*n_text2;
	int				*n_text3;
	int				*n_text4;
	int				bpp;
	int				ls;
	int				endian;
	int				tex_x;
	int				tex_y;
	int				text_width;
	int				text_height;
	int				n_of_2s;
	int				d;
	int				sprite_texx;
	int				sprite_texy;
	int				sprite_screen_x;
	int				sprite_height;
	int				sprite_width;
	int				*sprite_order;
	double			*sprite_distance;
	double			*sprite_x;
	double			*sprite_y;
	double			sprite_pos_x;
	double			sprite_pos_y;
	double			transform_x;
	double			transform_y;
	double			invdet;
	double			wall_x;
	double			camara_x;
	double			tex_pos;
	double			step;
	double			*z_buffrer;
	t_keys			*keys;
	t_player		*player;
	t_vector		*ray;
	t_vector		*plane;
	t_vector		*init_pos;
	t_color			*act_wall;
	t_color			*ceiling;
	t_color			*floor;
	t_errors		*errors;
}				t_data;

void			save_bmp		(t_data *data);
void			sprites			(t_data *data);
int				keys_released	(int key, t_data *data);
int				keys_press		(int key, t_data *data);
void			keys_change		(t_data *data, t_keys *keys);
void			rot_lf			(t_data *data);
void			rot_rt			(t_data *data);
void			move_rt			(t_data *data);
void			move_lf			(t_data *data);
void			move_fwd		(t_data *data);
void			move_back		(t_data *data);
int				salida			(t_data *data);
void			load_images		(t_data *data);
void			draw_text		(t_data *data);
void			print_errors	(t_data *data);
void			arg_error		(t_data *data);
void			error_resolution(t_data *data, int i);
void			error_color		(t_data *data, int i);
int				fill			(t_data *data, int i, int j);
int				start_fill		(t_data *data);
void			save_2s			(t_data *data, int n_of_2s);
void			remove2			(t_data *data);
void			mapper			(t_data *data);
void			check_map		(t_data *data);
void			copy_map		(t_data *data);
void			get_data		(t_data *data);
void			resolution		(t_data *data, int i);
void			start_direction	(t_data *data);
void			text			(t_data *data, char *dir, int i);
int				drawer			(t_data *data);
void			engine			(t_data *data, t_player *player,
								t_vector *ray, t_vector *plane);
void			rgb_to_hex		(t_data *data);
void			color			(t_data *data, char dir, int i);
void			color_ceiling	(t_data *data, int i);
int				btwsp			(t_data *data, int i);
int				errors			(t_data *data);
void			main_loop		(t_data *data);
void			init			(t_data *data);
void			go_dark			(t_data *data);
/*
** **************************************************************************
**									 GNL
** **************************************************************************
*/
int				get_next_line	(int fd, char **line);
char			*ft_strjoin		(char const *s1, char const *s2);
size_t			ft_strlen		(const char *str);
char			*ft_strdup		(const char *s);
char			*ft_strchr		(const char *s, int c);
char			*ft_substr		(char const *s, unsigned int start, int len);
int				ft_aux			(char **line);
int				ft_checker		(int fd, char **line, char **file, int ret);
/*
** **************************************************************************
**								   libft
** **************************************************************************
*/
void			*ft_bzero		(void *s, size_t n);
int				ft_atoi			(const char *str);
int				ft_strcmp		(const char *s1, const char *s2);
int				ft_strncmp		(const char *s1, const char *s2, size_t n);
char			*ft_strnstr		(const char *haystack, const char *needle,
								size_t len);
#endif

#	ifndef BUFFER_SIZE
#	define BUFFER_SIZE 42
#	endif
