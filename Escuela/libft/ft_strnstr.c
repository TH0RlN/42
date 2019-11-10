/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 11:19:58 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/10 12:00:48 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	else
	{
		while (haystack[i] != '\0' && i < len)
		{
			j = 0;
			if (haystack[i] == needle[j])
			{
				while (haystack[i + j] == needle[j])
					j++;
				if (needle[j] == '\0')
					return ((char *)haystack + i);
			}
			i++;
		}
	}
	return (0);
}
