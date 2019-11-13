/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:37:51 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/13 16:54:53 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	**alloc_counter(char **tab, char *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		write(1, 'c', 1);
		printf("counter");
		if (s[i] == c)
			j++;
		i++;
	}
	if (!(tab = malloc(i * sizeof(char*))))
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
		printf("maker fuera");
		while (s[i] != c)
		{
			printf("maker dentro");
			tab[j][k] = s[i];
			i++;
			k++;
		}
		k = 0;
		j++;
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
			printf("split %i %i", i, j);
			i++;
			j++;
		}
		if (!(tab[k] = malloc(j * sizeof(char))))
			return (0);
		k++;
	}
	return (maker(tab, (char*)s, c));
}

int main()
{
	// ver varios espacios
	char *k = "Juan alberto es una persona que vive en su casa";
	char **c;
	int j;

	j = 0;
	write(1, 'm', 1);
	c = ft_split(k, 32);
	while (j < 9)
	{
		printf("%s", c[j]);
		j++;
	}
	return (0);
}