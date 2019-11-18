/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:34:53 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/17 18:30:45 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*auxdest;
	unsigned char	*auxsrc;

	auxdest = (unsigned char *)dest;
	auxsrc = (unsigned char *)src;
	i = 0;
	while (i < n && (unsigned char)c != auxsrc[i])
	{
		auxdest[i] = auxsrc[i];
		i++;
	}
	if (auxsrc[i] == (unsigned char)c)
		auxdest[i] = (unsigned char)c;
	if (auxsrc[i] == (unsigned char)c)
		return (dest + i + 1);
	else
		return (0);
}
