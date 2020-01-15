/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 09:52:48 by rarias-p          #+#    #+#             */
/*   Updated: 2020/01/14 17:35:48 by rarias-p         ###   ########.fr       */
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

void	fill(char **rest, char **line)
{
	int i;

	i = 0;
	while ((*rest)[i] != '\n' && (*rest)[i] != '\0')
		i++;
	*line = ft_substr(*rest, 0, i);
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
		if (check_for_nl(rest[fd]) == 1)
			break ;
	}
	if (test < 0)
		return (-1);
	fill(&rest[fd], line);
	rest[fd][BUFFER_SIZE] = '\0';
	rest[fd] = ft_strchr(buff, '\n') + 1;
	return (test == BUFFER_SIZE ? 1 : 0);
}
