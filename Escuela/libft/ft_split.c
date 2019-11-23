/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:37:51 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/22 18:06:16 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**alloc_counter(char **tab, char *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			j++;
		i++;
	}
	if (!(tab = malloc((j + 1) * sizeof(char*))))
		return (0);
	return (tab);
}

static char	**maker(char **tab, char *s, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] != c)
		{
			tab[j][k] = s[i];
			i++;
			k++;
		}
		tab[j][k] = '\0';
		k = 0;
		j++;
		i++;
	}
	tab[j] = NULL;
	return (tab);
}

char		**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	tab = NULL;
	i = 0;
	k = 0;
	tab = alloc_counter(tab, (char *)s, c);
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			j++;
		}
		if (!(tab[k] = malloc(j * sizeof(char))))
			return (0);
		k++;
		i++;
	}
	return (maker(tab, (char*)s, c));
}
