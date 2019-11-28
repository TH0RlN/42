/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 09:08:23 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/28 10:14:06 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			lenther(char const *s1, char const *set)
{
	int i;
	int j;
	int len;
	int ttl_len;

	i = 0;
	j = ft_strlen(s1) - 1;
	ttl_len = ft_strlen(s1);
	while (ft_checkset(s1[i], (char *)set) == 1 && s1)
		i++;
	while (j >= 0 && ft_checkset(s1[j], (char *)set) == 1)
	{
		j--;
		i++;
	}
	len = ttl_len - i;
	if (len < 0)
		len = 0;
	return (len);
}

static char			*filler(char *trim, char const *s1, char const *set)
{
	int len;
	int i;
	int j;

	len = ft_strlen(s1) - 1;
	i = 0;
	j = 0;
	while (ft_checkset(s1[len], set) == 1 && len >= 0)
		len--;
	len++;
	while (ft_checkset(s1[i], set) == 1 && s1[i])
		i++;
	while (i < len && s1[i])
	{
		trim[j] = s1[i];
		i++;
		j++;
	}
	trim[j] = '\0';
	return (trim);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		lenth;

	if (!s1 || !set)
		return (NULL);
	lenth = lenther(s1, set);
	if (lenth <= 0)
		return (ft_strdup(""));
	if (!(trim = malloc(lenth + 1)))
		return (NULL);
	trim = filler(trim, (char *)s1, (char *)set);
	return (trim);
}
