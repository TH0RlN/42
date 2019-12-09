/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 12:31:15 by abarral-          #+#    #+#             */
/*   Updated: 2019/11/25 17:07:31 by abarral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_start(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	boolean;

	i = -1;
	boolean = 'T';
	while (boolean == 'T')
	{
		boolean = 'F';
		i++;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				boolean = 'T';
			j++;
		}
	}
	return (i);
}

static int		ft_end(char const *s1, char const *set, int start)
{
	int		i;
	int		j;
	char	boolean;

	i = 0;
	while (s1[i])
		i++;
	i = i == 0 ? 0 : i - 1;
	boolean = 'T';
	while (start < i && boolean == 'T')
	{
		boolean = 'F';
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				i--;
				boolean = 'T';
			}
			j++;
		}
	}
	return (i);
}

static char		*ft_trim(char const *s1, int start, int end)
{
	char	*trimmed;
	int		i;
	int		j;

	if (!(trimmed = malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	i = start;
	j = 0;
	while (i <= end)
	{
		trimmed[j] = s1[i];
		i++;
		j++;
	}
	trimmed[j] = '\0';
	return (trimmed);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*trimmed;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (s1[0] == '\0')
	{
		if (!(trimmed = malloc(sizeof(char) * 1)))
			return (NULL);
		trimmed[0] = '\0';
		return (trimmed);
	}
	start = ft_start(s1, set);
	end = ft_end(s1, set, start);
	trimmed = ft_trim(s1, start, end);
	return (trimmed);
}
