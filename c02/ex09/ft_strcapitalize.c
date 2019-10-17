/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:51:36 by rarias-p          #+#    #+#             */
/*   Updated: 2019/10/17 11:53:08 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_alllowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 64 && str[i] < 91)
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	ft_alllowcase(str);
	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0)
		{
			if (str[i] > 96 && str[i] < 123)
				str[i] -= 32;
			i++;
		}
		else
		{
			if (str[i] > 96 && str[i] < 123)
			{
				if (!((str[i - 1] > 96 && str[i - 1] < 123) ||
					(str[i - 1] > 64 && str[i - 1] < 91) ||
					(str[i - 1] > 47 && str[i - 1] < 58)))
					str[i] -= 32;
			}
			i++;
		}
	}
	return (str);
}
