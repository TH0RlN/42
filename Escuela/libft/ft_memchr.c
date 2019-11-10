/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:09:20 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/06 17:04:59 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	*auxs;

	i = 0;
	auxs = (char *)s;
	while (i < n)
	{
		if (auxs[i] == (char)c)
			return (auxs + i);
		i++;
	}
	return (0);
}
