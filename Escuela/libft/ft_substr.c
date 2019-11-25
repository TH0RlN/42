/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:45:47 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/24 16:58:17 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	i;
	char	*k;
	size_t	real_len;
	size_t	len2;

	real_len = 0;
	if (!s)
		return (0);
	while (s[start + real_len] != '\0')
		real_len++;
	len2 = (len <= real_len) ? len : real_len;
	if (!(k = malloc((len2 + 1) * sizeof(char))))
		return (0);
	j = start;
	i = 0;
	while (s[j] != '\0' && i < len)
	{
		k[i] = s[j];
		j++;
		i++;
	}
	k[i] = '\0';
	return (k);
}
