/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:41:06 by abarral-          #+#    #+#             */
/*   Updated: 2019/12/01 17:58:20 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, int len)
{
	char	*dest;
	int		i;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	dest = (char *)malloc(((int)len + 1) * sizeof(char));
	if (dest == '\0')
		return (dest);
	i = start;
	while (s[i] && len > 0)
	{
		dest[i - start] = s[i];
		i++;
		len--;
	}
	dest[i - start] = '\0';
	return (dest);
}
