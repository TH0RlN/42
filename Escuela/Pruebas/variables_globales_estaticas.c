/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables_globales_estaticas.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 10:05:23 by rarias-p          #+#    #+#             */
/*   Updated: 2019/12/09 10:24:25 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int rock = 42; //comenta esta línea para compilar con "-D rock=xx" (donde de xx es un valor para una variable tipo int)

int main()
{
	printf("%d", rock);
	return (0);
}