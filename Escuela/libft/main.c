/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 08:55:37 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/15 09:00:02 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main()
{
	char c = 'a';
	char k[] = "juan alberto";

	printf("%s", ft_strrchr(k, c));
}