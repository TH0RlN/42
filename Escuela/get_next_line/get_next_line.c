/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 09:52:48 by rarias-p          #+#    #+#             */
/*   Updated: 2019/12/11 10:31:18 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

int		get_next_line(int fd, char **line)
{
	int test;
	char prueba[999];
	
	//test = read(fd, *line, BUFFER_SIZE);
	//printf("%s || %d\n", *line, test);
	line = NULL;
	test = read(fd, prueba, 1);
	prueba[ft_strlen(prueba)] = '\0';
	printf("%s || %d\n", prueba, test);
	return (test);
}