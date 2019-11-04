/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 10:55:19 by rarias-p          #+#    #+#             */
/*   Updated: 2019/10/20 23:39:34 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	ft_translate(char **argv, char  *lib, int argch)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (argv[1][i] != '\0')
	{
		while (lib[j] != argv[1][i])
			j++;
		if (lib[j] == argv[1][i])
			ft_getlit(lib, argv, i, j);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	int		rfd;
	int		len;
	char	buff[1024];
	char	*lib;

	len = 0;
	rfd = 30;
	if (argc == 2)
	{
		fd = open("numbers.dict", O_RDONLY);
		while (rfd == 30)
		{
			rfd = read(fd, &buff, 30);
			if (rfd == 30)
				len += 30;
		}
		len += rfd;
		close(fd);
		lib = (char *)malloc(sizeof(char) * len);
		fd = open(argv[1], O_RDONLY);
		read(fd, &buff, len);
		lib = buff;
		ft_translate(argv, lib, 1);
	}
}

void	ft_getlit(char *lib, char **argv, int i, int j)
{
	while (lib[j] != '\n')
	{
	
		i++;
	}
}
