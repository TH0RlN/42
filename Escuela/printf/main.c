/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 17:28:29 by rarias-p          #+#    #+#             */
/*   Updated: 2020/03/04 10:17:12 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	void *a01;
	void *a02;
	void *a03;
	void *a04;

	a01 = malloc(2);
	a02 = malloc(2);
	a03 = malloc(2);
	a04 = malloc(2);
	printf("  -->>  %u\n", ft_printf("%p %p", &a01, &a02));
	printf("  -->>  %u\n", printf("%p %p", &a01, &a02));
	free(a01);
	free(a02);
	free(a03);
	free(a04);
	getchar();
	return (0);
}
