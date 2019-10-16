/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 20:16:38 by edramire          #+#    #+#             */
/*   Updated: 2019/10/13 20:59:57 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_bt_row(int test, char s);
int		ft_rem_hex_on_row(int hex, int row_nbr, int *row, int *col);
void	ft_get_knowledge_table(int *arr);

int		ft_check_bt_row(int test, char s)
{
	int		i;
	char	res[6];
	int		hex;
	int		tab[24];

	ft_get_knowledge_table(tab);
	hex = *(tab + s - 'A');
	if ((hex & test) != hex)
		return (0);
	return (hex);
}

int		ft_rem_hex_on_row(int hex, int row_nbr, int *row, int *col)
{
	return (0);
}
