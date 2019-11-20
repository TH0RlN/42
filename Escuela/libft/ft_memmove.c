/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:33:26 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/19 13:23:10 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	aux[n];
	char	*auxdest;
	char	*auxsrc;

	auxdest = (char *)dest;
	auxsrc = (char *)src;
	i = 0;
	if (dest == '\0' || src == '\0')
		return (0);
	while (i < n)
	{
		aux[i] = auxsrc[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		auxdest[i] = aux[i];
		i++;
	}
	return (dest);
}
