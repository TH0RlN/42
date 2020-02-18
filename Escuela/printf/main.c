/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 17:28:29 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/18 16:36:31 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	void *a01;
	void *a02;
	void *a03;

	a01 = malloc(2);
	a02 = malloc(2);
	a03 = malloc(2);
	printf("  -->>  %u\n", ft_printf("%p %p %p", &a01, &a02, &a03));
	printf("  -->>  %u\n", printf("%p %p %p", &a01, &a02, &a03));
	free(a01);
	free(a02);
	free(a03);
	return (0);
}
