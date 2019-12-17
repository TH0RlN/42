/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 09:52:48 by rarias-p          #+#    #+#             */
/*   Updated: 2019/12/17 16:46:23 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_for_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] = '\n')
			return (1);
		i++;
	}
	return (0);
}

void	fill(char *rest, char *line)
{
	int pos_line;
	int pos_rest;

	pos_line = ft_strlen(line);
	
}

int		get_next_line(int fd, char **line)
{
	static char	*rest[4096];
	char		buff[BUFFER_SIZE];
	int			test;

	while ((test = read(fd, buff, BUFFER_SIZE) > 0))
	{
		buff[BUFFER_SIZE] = '\0';
		if (!(rest[fd]))
			rest[fd] = ft_strdup(buff);
		else
			rest[fd] = ft_strjoin(rest[fd], buff);
		if (check_for_nl(rest[fd]) == 1)
			break ;
	}
	fill(rest[fd], *line);
}
