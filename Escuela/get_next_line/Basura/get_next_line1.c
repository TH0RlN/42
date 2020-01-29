/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 09:52:48 by rarias-p          #+#    #+#             */
/*   Updated: 2020/01/23 15:36:18 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		fill(char **rest, char **line, int fd)
{
	int		i;
	char	*aux;

	i = 0;
	while (rest[fd][i] != '\n' && rest[fd][i] != '\0')
		i++;
	if (rest[fd][i] == '\n')
	{
		*line = ft_substr(rest[fd], 0, i);
		aux = ft_strdup((&((rest[fd])[i + 1])));
		free(rest[fd]);
		rest[fd] = aux;
		return (1);
	}
	else
	{
		*line = ft_strdup(rest[fd]);
		free(rest[fd]);
		rest[fd] = NULL;
		return (0);
	}
}

int		empty(char **line)
{
	*line = ft_strdup("");
	return (0);
}

int		returner(char **rest, char **line, int fd, int test)
{
	if (test < 0)
		return (-1);
	return (!rest[fd] && test == 0 ? empty(line) : fill(rest, line, fd));
}

int		get_next_line(int fd, char **line)
{
	static char	*rest[4096];
	char		*buff;
	int			test;
	char		*aux;

	if (!(buff = malloc((BUFFER_SIZE + 1) * sizeof(char)))
	|| !line || fd < 0)
		return (-1);
	while ((test = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[test] = '\0';
		if (!(rest[fd]))
			rest[fd] = ft_strdup(buff);
		else
		{
			aux = ft_strjoin(rest[fd], buff);
			free(rest[fd]);
			rest[fd] = aux;
		}
		if (ft_strchr(rest[fd], '\n'))
			break ;
	}
	free(buff);
	return (returner(rest, line, fd, test));
}
