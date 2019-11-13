/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:37:51 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/13 08:54:21 by rarias-p         ###   ########.fr       */
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

char	**maker(char **tab)
{
	
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
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
	}
	return (maker(tab));
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