/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:09:30 by edramire          #+#    #+#             */
/*   Updated: 2019/10/13 19:23:04 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_row(int test, char *s);
int		ft_set_hex_on_row(int hex, int row_nbr, int *row, int *col);
int		ft_set_hex_on_col(int hex, int row_nbr, int *row, int *col);
int		ft_get_common_bits(char *s, int *tab);
void	ft_set_hex(int hex, int row, int col, int *arr);
void	ft_get_knowledge_table(int *arr);

int		ft_set_hex_on_row(int hex, int row_nbr, int *row, int *col)
{
	int i;
	int mask;

	mask = 0xf000;
	i = 0;
	while (i < 4)
	{
		if ((mask & hex) > 0)
		{
			ft_set_hex((hex & mask) >> (3 - i) * 4, row_nbr, i, row);
			ft_set_hex((hex & mask) >> (3 - i) * 4, i, row_nbr, col);
		}
		i++;
		mask >>= 4;
	}
	return (1);
}

int		ft_set_hex_on_col(int hex, int row_nbr, int *row, int *col)
{
	int i;
	int mask;

	mask = 0xf000;
	i = 0;
	while (i < 4)
	{
		if ((mask & hex) > 0)
		{
			ft_set_hex((hex & mask) >> (3 - i) * 4, row_nbr, i, col);
			ft_set_hex((hex & mask) >> (3 - i) * 4, i, row_nbr, row);
		}
		i++;
		mask >>= 4;
	}
	return (1);
}

void	ft_set_hex(int hex, int row, int col, int *arr)
{
	int inv;
	int i;
	int row_mask;
	int col_mask;

	inv = (hex ^ 0xf) & 0xf;
	row_mask = 0;
	i = 0;
	while (i < 4)
	{
		row_mask |= (i == col ? hex : inv) << (3 - i) * 4;
		i++;
	}
	i = (3 - col) * 4;
	col_mask = (inv << i) | ((0xf << i) ^ 0xffff);
	i = 0;
	while (i < 4)
	{
		if (i++ == row)
			*arr++ &= row_mask;
		else
			*arr++ &= col_mask;
	}
}

int		ft_check_row(int test, char *s)
{
	int		i;
	char	res[6];
	int		hex;
	int		tab[24];

	ft_get_knowledge_table(tab);
	i = 0;
	while (*s != '\0')
	{
		hex = *(tab + *s - 'A');
		if ((hex & test) == hex)
			res[i++] = *s;
		s++;
	}
	res[i] = '\0';
	if (i == 0)
		return (-1);
	else if (i > 1)
		return (ft_get_common_bits(res, tab));
	return (*(tab + *res - 'A'));
}
