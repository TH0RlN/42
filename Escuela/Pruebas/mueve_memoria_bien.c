/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mueve_memoria_bien.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:55:53 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/25 13:04:47 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	aux[n];
	char	*auxdest;
	char	*auxsrc;

	auxdest = (char *)dest;
	auxsrc = (char *)src;
	i = 0;
	if (dest == NULL && src == NULL && n)
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
