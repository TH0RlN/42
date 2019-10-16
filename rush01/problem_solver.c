/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   problem_solver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiez-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 21:43:56 by cdiez-me          #+#    #+#             */
/*   Updated: 2019/10/13 21:15:35 by cdiez-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define SIZE 3

int	is_valid(char* tb)
{
	if (tb[0] == tb[1] || tb[0] == tb[2] || tb[0] == tb[3] || (tb[1]!='0' && tb[4]==tb[1]) || (tb[2] != '0' && tb[2] == tb[5]) || (tb[1] !='0' && tb[1]==tb[2]) || (tb[4]!='0' && tb[4]==tb[5]) || (tb[5]!='0' && tb[5]==tb[3]))
	{
		return 0;
	}
	return 1;
}

int	problem_solver(char* tb, int pos)
{
	int	i;

	if (pos == SIZE * SIZE)
		return 1;
	i = 1;
	while (i < SIZE + 1)
	{
		tb[pos] = i + '0';
		for(int j =0; j<9; j++)
			printf("%c ", tb[j]);
		printf("\n");
		if (is_valid(tb))
			if (problem_solver(tb, pos + 1))
					return 1;
		tb[pos] = '0';
		i++;
	}
	return 0;
}


int main2()
{
	char tb[SIZE*SIZE] = {'0','0','0','0', '0','0','0','0','0'};
	if(problem_solver(tb, 0))
	{
		for(int i =0; i<SIZE *SIZE; i++)
			printf("%c ", tb[i]);
	}
	return 1;

}
