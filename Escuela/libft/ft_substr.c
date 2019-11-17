/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:45:47 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/17 14:04:02 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	i;
	char	*k;
	size_t	real_len;

	real_len = 0;
	while (s[start + real_len] != '\0')
		real_len++;
	if (!(k = malloc(real_len * sizeof(char))))
		return (0);
	j = start;
	i = 0;
	while (s[j] != '\0' && i < len)
	{
		k[i] = s[j];
		j++;
		i++;
	}
	return (k);
}
