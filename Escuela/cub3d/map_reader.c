/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:56:51 by rarias-p          #+#    #+#             */
/*   Updated: 2020/09/03 19:49:27 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line_bonus.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*aux;

	aux = (char *)s;
	i = 0;
	while (i < n)
	{
		aux[i] = '\0';
		i++;
	}
	return (s);
}

void	get_data(char *map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 'R' && map[i + 1] == " ")
			resolution()
	}
}

void	get_lines(int fd)
{
	char	*map;
	char	*line;

	ft_bzero(map, 1);
	while (get_next_line(fd, &line))
	{
		map = *map ? ft_strjoin(ft_strjoin(map, line), "\n") :
		ft_strjoin(ft_strdup(line), "\n");
	}
	map = *map ? ft_strjoin(ft_strjoin(map, line), "\n") : ft_strdup(line);
	printf("%s", map);
}

int		main(int argc, char const *argv[])
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	get_lines(fd);
}
