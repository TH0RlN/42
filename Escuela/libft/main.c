/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:12:38 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/23 16:27:02 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int  main()
{
	char *str = "the cake is a lie !\0I'm hidden lol\r\n";
	char buff1[0xF00] = "there is no stars in the sky";
	char buff2[0xF00] = "there is no stars in the sky";
	size_t max = strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4;
	
	ft_strlcat(buff2, str, max);
	strlcat(buff1, str, max);
	
	printf("%s\n", buff2);
	printf("%s\n", buff1);
}