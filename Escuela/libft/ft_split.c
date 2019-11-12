/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:37:51 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/12 17:05:02 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	tab = malloc(ft_strlen(s) * sizeof(char));
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != c)
		{
			tab[j][k] = s[i];
			i++;
		}
		i++;
		j++;
	}
	return (tab);
}


int main()
{
	// ver varios espacios
	char *k = "Juan alberto es una persona que vive en su casa";
	char **c;
	int j;

	j = 0;
	c = ft_split(k, ' ');
	while (j < 9)
	{
		printf("%s", c[j]);
		j++;
	}
	return (0);
}