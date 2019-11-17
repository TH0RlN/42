/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:33:26 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/17 13:17:34 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	*aux;
	char	*auxdest;
	char	*auxsrc;

	auxdest = (char *)dest;
	auxsrc = (char *)src;
	i = 0;
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
