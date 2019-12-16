/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 09:52:48 by rarias-p          #+#    #+#             */
/*   Updated: 2019/12/16 09:45:28 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE + 1];
	int			test;
	
	if (buff != NULL)
		*line = ft_strjoin(*line, buff);
	if(fd < 0 || !line || !BUFFER_SIZE)
		return (-1);
	while ((test = read(fd, buff, BUFFER_SIZE)))
	{
		if (ft_strchr(buff, '\n') != NULL)
			break;
	}
	*buff = *ft_strchr(buff, '\n');
	return (0);
}