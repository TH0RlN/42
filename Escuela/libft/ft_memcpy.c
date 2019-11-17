/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:11:26 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/17 13:52:22 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*auxdest;
	char	*auxsrc;

	auxdest = (char *)dest;
	auxsrc = (char *)src;
	i = 0;
	while (i < n)
	{
		auxdest[i] = auxsrc[i];
		i++;
	}
	return (dest);
}
