/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:10:32 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/17 13:49:51 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*ward;
	unsigned long	i;

	if (!(ward = malloc(count * size)))
		return (0);
	i = 0;
	while (i < (count * size) / 4)
	{
		ward[i] = '\0';
		i++;
	}
	return (ward);
}
