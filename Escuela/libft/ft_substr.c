/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:45:47 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/12 12:15:14 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		j;
	int		i;
	char	*k;
	int		real_len;

	while (s[start + real_len] != '\0')
		real_len++;
	if (!(k = malloc(real_len * sizeof(char))))
		return (0);
	j = start;
	i = 0;
	while (s[j] != '\0')
	{
		k[i] = s[j];
		j++;
		i++;
	}
	return (k);
}
