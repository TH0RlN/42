/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:57:22 by rarias-p          #+#    #+#             */
/*   Updated: 2019/10/20 10:07:48 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd;

	if (argc == 2)
		printf("%s", argv[1]);
	if (argc == 3)
	{
		fd = open(argv[1], O_RDWR);
		if (fd < 0)
		{
			close(fd);
			write(1, "Error", 5);
		}
		else
		{
			printf("%s\n%i", argv[2], fd);
			close(fd);
		}
	}
}
