/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:37:51 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/27 18:58:21 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			get_nword(char const *s, char c)
{
	unsigned char		*str;
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = 0;
	str = (unsigned char *)s;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
			j++;
		while (str[i] != c && str[i])
			i++;
	}
	return (j);
}

static int			get_len(char const *s, char c, char **str)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
			{
				j++;
				i++;
			}
			if (!(str[k] = malloc(sizeof(char) * j + 1)))
				return (0);
			k++;
		}
		else
			i++;
	}
	return (1);
}

static void			init(unsigned int *i, unsigned int *j)
{
	*i = 0;
	*j = 0;
}

char				**ft_split(char const *s, char c)
{
	char			**str;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	if (s == 0)
		return (0);
	init(&i, &j);
	if (!(str = (char**)malloc(sizeof(char*) * (get_nword(s, c) + 1))))
		return (0);
	if (!(get_len(s, c, str)))
		return (NULL);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		k = 0;
		while (s[i] != c && s[i])
			str[j][k++] = s[i++];
		str[j++][k] = '\0';
		while (s[i] == c)
			i++;
	}
	str[j] = 0;
	return (str);
}
