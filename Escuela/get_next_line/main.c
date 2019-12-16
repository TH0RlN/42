/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 10:22:15 by rarias-p          #+#    #+#             */
/*   Updated: 2019/12/16 10:25:19 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

int	main(void)
{
	int		fd;
	int		i;
	int		j;
	char	*line = 0;
	char	*lineadress[66];

	j = 1;
	if (!(fd = open("texto.txt", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		lineadress[j - 1] = line;
		j++;
	}
	//printf("%s\n", line);
	free(line);
	close(fd);
	while (--j > 0)
		free(lineadress[j - 1]);
}
