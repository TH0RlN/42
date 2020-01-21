/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 09:52:48 by rarias-p          #+#    #+#             */
/*   Updated: 2020/01/21 12:54:57 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		fill(char **rrest, char **line, int fd)
{
	int		i;
	char	*aux;

	i = 0;
	while (rrest[fd][i] != '\n' && rrest[fd][i] != '\0')
		i++;
	if (rrest[fd][i] == '\n')
	{
		*line = ft_substr(rrest[fd], 0, i);
		aux = ft_strdup((&((rrest[fd])[i + 1])));
		free(rrest[fd]);
		rrest[fd] = aux;
		return (1);
	}
	else
	{
		*line = ft_strdup(rrest[fd]);
		free(rrest[fd]);
		rrest[fd] = 0;
		return (0);
	}
}

int		empty(char **line)
{
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*rest[4096];
	char		buff[BUFFER_SIZE + 1];
	int			test;

	if (!fd || !line || !BUFFER_SIZE || fd < 0)
		return (-1);
	while ((test = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[test] = '\0';
		if (!(rest[fd]))
			rest[fd] = ft_strdup(buff);
		else
			rest[fd] = ft_strjoin(rest[fd], buff);
		if (ft_strchr(rest[fd], '\n'))
			break ;
	}
	if (test < 0)
		return (-1);
	return (!rest[fd] && test == 0 ? empty(line) : fill(rest, line, fd));
}
