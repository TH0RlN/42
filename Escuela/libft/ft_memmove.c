/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:33:26 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/25 13:07:43 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p;
	unsigned char	*j;
	unsigned int	i;

	p = dst;
	j = (unsigned char *)src;
	i = -1;
	if (dst == 0 && src == 0)
		return (0);
	if (p > j)
		while ((int)(--len) >= 0)
			p[len] = j[len];
	else
		while (++i < len)
			p[i] = j[i];
	return (dst);
}
