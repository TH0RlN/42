/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 11:19:58 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/18 16:08:17 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		test(int len, char *haystack)
{
	if (len < 1)
		return (0);
	else if (haystack[0] == '\0')
		return (0);
	else
		return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	else if (test(len, (char *)haystack) == 0)
		return (0);
	else
	{
		while (haystack[i] != '\0' && i < len)
		{
			j = 0;
			if (haystack[i] == needle[j])
			{
				while (haystack[i + j] == needle[j] && (i + j) < len)
					j++;
				if (needle[j] == '\0')
					return ((char *)haystack + i);
			}
			i++;
		}
	}
	return (0);
}
