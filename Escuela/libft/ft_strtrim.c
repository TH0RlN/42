/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 09:08:23 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/27 16:33:21 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			lenther(char const *s1, char const *set)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s1[i])
	{
		if (ft_checkset(s1[i], set) == 0)
			len++;
		i++;
	}
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char *trim;

	if (!(trim = malloc(lenther(s1, set))))
		return (NULL);
	
}
