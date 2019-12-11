/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 09:52:48 by rarias-p          #+#    #+#             */
/*   Updated: 2019/12/11 12:35:36 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

int		get_next_line(int fd, char **line)
{
	int test;
	char buff[30];
	static char *prueba[999];

	line = NULL;
	buff[0] = '\0';
	test = read(fd, buff, 10);
	buff[test] = '\0';
	ft_memccpy(buff, buff, '\n', BUFFER_SIZE);
	if (!*prueba)
		*prueba = ft_strdup(buff);
	else
		*prueba = ft_strjoin(*prueba, buff);
	printf("%s || %d\n", *prueba, test);
	return (test);
}