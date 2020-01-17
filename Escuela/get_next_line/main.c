/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 10:22:15 by rarias-p          #+#    #+#             */
/*   Updated: 2020/01/17 10:27:17 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
//#include "../libft/libft.h"
//
//int	main(void)
//{
//	int		fd;
//	int		i;
//	int		j;
//	char	*line = 0;
//
//	j = 1;
//	if (!(fd = open("texto.txt", O_RDONLY)))
//	{
//		printf("\nError in open\n");
//		return (0);
//	}
//	while ((i = get_next_line(fd, &line)) > 0)
//		printf("%s\n", line);
//
//	free(line);
//	close(fd);
//}

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main (void)
{
	int fd;
	char *prueba;
	int x;
	fd = open("ANewHope.txt", O_RDONLY);
	do
	{
	x = get_next_line(fd, &prueba);
	printf("%d %s\n", x, prueba);
	free (prueba);
	}
	while (x > 0);
	return (0);
}
