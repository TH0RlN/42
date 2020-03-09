/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 10:39:39 by rarias-p          #+#    #+#             */
/*   Updated: 2020/03/09 10:48:32 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef struct	s_examprintf
{
	char	*format;
	void	*data;
	int		len;
	int		width;
	int		dot;
	int		precision;
}				t_examprintf;


int		ft_printf(const char *format, ...)
{
    t_examprintf tab;
}
