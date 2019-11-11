/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:10:32 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/11 11:12:05 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*ward;
	int		i;

	ward = malloc(count * size);
	i = 0;
	while (i < (count * size) / 4)
	{
		ward[i] = '\0';
		i++;
	}
	return (ward);
}
