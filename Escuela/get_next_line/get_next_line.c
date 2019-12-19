/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 09:52:48 by rarias-p          #+#    #+#             */
/*   Updated: 2019/12/19 11:19:23 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_for_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	fill(char *rest, char *line)
{
	size_t pos_line;
	size_t pos_rest;

	if (line)
		pos_line = ft_strlen(line);
	else
		pos_line = 0;
	pos_rest = 0;
	while (rest[pos_rest] != '\n' && rest[pos_rest] != '\0')
	{
		line[pos_line] = rest[pos_rest];
		pos_line++;
		pos_rest++;
	}
	line[pos_line] = '\0';
}

int		get_next_line(int fd, char **line)
{
	static char	*rest[4096];
	char		buff[BUFFER_SIZE + 1];
	int			test;

	if (!fd || !line || !BUFFER_SIZE || fd < 0)
		return (-1);
	while ((test = read(fd, buff, BUFFER_SIZE) > 0))
	{
		if (test < 0)
			return (-1);
		buff[BUFFER_SIZE] = '\0';
		if (!(rest[fd]))
			rest[fd] = ft_strdup(buff);
		else
			rest[fd] = ft_strjoin(rest[fd], buff);
		if (check_for_nl(rest[fd]) == 1)
			break ;
	}
	fill(rest[fd], *line);
	return (test == BUFFER_SIZE ? 1 : 0);
}
