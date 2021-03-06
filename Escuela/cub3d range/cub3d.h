/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 17:22:45 by rarias-p          #+#    #+#             */
/*   Updated: 2020/09/11 19:32:42 by rarias-p         ###   ########.fr       */
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

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef	struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef	struct	s_data
{
	int			fd;
	int			resx;
	int			resy;
	int			lines_map;
	char		*map;
	char		**matrix_map;
	char		**order_map;
	char		*text_no;
	char		*text_so;
	char		*text_we;
	char		*text_ea;
	char		*text_sp;
	char		*line;
	t_pos		*init_pos;
	t_color		*ceiling;
	t_color		*floor;
}				t_data;

void			change_to_zero	(t_data *data, int i, int j);
void			check_1s		(t_data *data, int i, int j);
void			get_order		(t_data *data);
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
