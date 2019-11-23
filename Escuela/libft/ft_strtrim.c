/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 09:08:23 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/22 17:00:35 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	comparator(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*hacedor(char const *s1, char const *set, char *newstr)
{
	int min;
	int max;
	int	i;

	min = 0;
	max = ft_strlen(s1) - 1;
	while (comparator(s1[min], set) == 1 && s1[min] != '\0')
		min++;
	while (comparator(s1[max], set) == 1 && max >= 0)
		max--;
	i = 0;
	while (min <= max)
	{
		newstr[i] = s1[min + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

static int	sizer(char const *s1, char const *set)
{
	int	size;
	int max;
	int i;

	i = 0;
	size = 0;
	max = ft_strlen(s1) - 1;
	while (comparator(s1[max], set) == 1 && max >= 0)
		max--;
	while (comparator(s1[i], set) == 1 && i <= max && s1[i] != '\0')
		i++;
	while (comparator(s1[i], set) == 0 && i <= max && s1[i] != '\0')
	{
		i++;
		size++;
	}
	return (size);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		size;
	char	*newstr;

	size = sizer(s1, set);
	if (!(newstr = malloc((size + 1) * sizeof(char))))
		return (0);
	newstr = hacedor(s1, set, newstr);
	return (newstr);
}
