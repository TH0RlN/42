/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:45:47 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/11 13:38:21 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	int i;
	int j;
	int k;
	int real_len;

	while (s[i] != start && s[i] != '\0')
		i++;
	j = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i + j])
		j++;
	
	
}