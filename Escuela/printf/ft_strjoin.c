/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:22:33 by abarral-          #+#    #+#             */
/*   Updated: 2020/02/04 17:35:24 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	if (!s1)
		return ((char *)s2);
	if (!(s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = -1;
	while (s1[++i])
		s[i] = s1[i];
	j = -1;
	while (s2[++j])
		s[i + j] = s2[j];
	s[i + j] = '\0';
	return (s);
}
