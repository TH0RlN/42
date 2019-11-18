/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 10:38:32 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/18 10:40:32 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = (size_t)ft_strlen(dest);
	i = 0;
	while (src[i] != '\0' && (len + i) < size)
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (len + i);
}
