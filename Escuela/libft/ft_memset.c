/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:37:11 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/06 17:28:38 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*memset(void *s, int c, size_t n)
{
	int		i;
	char	*aux;

	aux = (char *)s;
	i = 0;
	while (i < n)
	{
		aux[i] = c;
		i++;
	}
	return (s);
}