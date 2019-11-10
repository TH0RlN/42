/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:34:53 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/06 17:04:58 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*memccpy(void *dest, const void *src, int c, size_t n)
{
	int		i;
	char	*auxdest;
	char	*auxsrc;

	auxdest = (char *)dest;
	auxsrc = (char *)src;
	i = 0;
	while (i < n && (char)c != auxsrc[i])
	{
		auxdest[i] = auxsrc[i];
		i++;
	}
	if ((char)c != auxsrc[i])
		return (dest + i);
	else
		return (0);
}
