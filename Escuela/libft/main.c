/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:12:38 by rarias-p          #+#    #+#             */
/*   Updated: 2019/11/25 10:15:51 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int  main()
{
	t_list *data = NULL;
	data->content = malloc(6);
	data->content = "Pepelu";
	data->next = NULL;
	t_list *act_data = data;
	t_list *data2 = NULL;
	data2->content = "Lo que tu quieras";
	data2->next = NULL;
	ft_lstadd_back(&data2 ,data);
	while (act_data)
	{
		printf("%s", act_data->content);
		act_data = act_data->next;
	}
}