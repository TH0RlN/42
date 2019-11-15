/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:37:51 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/15 09:44:01 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**alloc_counter(char **tab, char *s, char c)
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
	if (!(tab = malloc(j * sizeof(char*))))
		return (0);
	return (tab);
}

char	**maker(char **tab, char *s, char c)
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
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

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

int	main(void)
{
	char	*k = "Juan alberto es una persona que vive en su casa";
	char	**c;
	int		j;

	j = 0;
	c = ft_split(k, 32);
	while (j < 10)
	{
		printf("%s\n", c[j]);
		j++;
	}
	return (0);
}
