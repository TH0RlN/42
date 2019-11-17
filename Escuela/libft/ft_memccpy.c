/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:34:53 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/17 13:17:17 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
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
