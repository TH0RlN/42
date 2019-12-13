/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 09:52:48 by rarias-p          #+#    #+#             */
/*   Updated: 2019/12/13 10:41:28 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char buff1[BUFFER_SIZE + 1];
	char		buff2[BUFFER_SIZE + 1];
	int			test;
	int			i;
		
	*line = NULL;
	if (!(test = read(fd, buff1, BUFFER_SIZE)))
		return (-1);
	buff1[BUFFER_SIZE] = '\0';
	i = 0;
	while (buff1[i] != '\n' && buff1[i] != '\0')
	{
		buff2[i] = buff1[i];
		i++;
	}
	buff2[i] = '\0';
	if (!*line)
		*line = ft_strdup(buff2);
	else
		*line = ft_strjoin(*line, buff2);	
	return(test < BUFFER_SIZE ? 0 : 1);
}