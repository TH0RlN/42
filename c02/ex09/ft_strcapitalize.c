/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:51:36 by rarias-p          #+#    #+#             */
/*   Updated: 2019/10/17 10:58:18 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_alllowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 96 && str[i] < 123)
			str[i] -= 32;
		i++;
	}
}

char *ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	ft_alllowcase(str);
	while(str[i] != '\0')
}
