/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:04:44 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/06 17:28:56 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	bzero(void *s, size_t n)
{
	int		i;
	char	*aux;

	aux = (char *)s;
	i = 0;
	while (i < n)
	{
		aux[i] = '\0';
		i++;
	}
	return (s);
}