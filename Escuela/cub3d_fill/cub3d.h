/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 17:22:45 by rarias-p          #+#    #+#             */
/*   Updated: 2020/12/12 17:53:38 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"

/*
** **************************************************************************
**									cub3d
** **************************************************************************
*/

typedef struct	s_vector
{
	float		x;
	float		y;
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

typedef struct	s_player
{
	t_vector	*position;
	t_vector	*direction;
}				t_player;


typedef	struct	s_data
{
	int			fd;
	int			resx;
	int			resy;
	int			check;
	int			counter;
	int			lines_map;
	char		direction;
	char		*map;
	char		**matrix_map;
	char		**fill_map;
	char		*text_no;
	char		*text_so;
	char		*text_we;
	char		*text_ea;
	char		*text_sp;
	char		*line;
	void		*mlx_ptr;
	void		*win_ptr;
	t_player	*player;
	t_vector	*init_pos;
	t_color		*ceiling;
	t_color		*floor;
	t_errors	*errors;
}				t_data;

void			error_resolution(t_data *data, int i);
void			error_color		(t_data *data, int i);
int				fill			(t_data *data, int i, int j);
int				start_fill		(t_data *data);
void			remove2			(t_data *data);
void			mapper			(t_data *data);
void			check_map		(t_data *data);
void			copy_map		(t_data *data);
void			get_data		(t_data *data);
void			resolution		(t_data *data, int i);
void			text			(t_data *data, char *dir, int i);
void			color			(t_data *data, char dir, int i);
void			color_ceiling	(t_data *data, int i);
int				btwsp			(t_data *data, int i);
int				errors			(t_data *data);
void			main_loop		(t_data *data);
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
int				ft_strncmp		(const char *s1, const char *s2, size_t n);
#endif

#	ifndef BUFFER_SIZE
#	define BUFFER_SIZE 42
#	endif
