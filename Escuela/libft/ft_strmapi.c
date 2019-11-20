/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:48:09 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/20 12:31:29 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*k;

	if (!s)
		return (0);
	if (!(k = malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (s[i])
	{
		k[i] = f(i, s[i]);
		i++;
	}
	k[i] = '\0';
	return (k);
}
