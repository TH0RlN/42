/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   knowlegde.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:09:03 by edramire          #+#    #+#             */
/*   Updated: 2019/10/13 19:40:26 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_get_knowledge_table(int *arr);
void	ft_get_dictionary(char arr[9][7]);
void	ft_strcpy(char *s1, char *s2);

void	ft_get_dictionary(char arr[9][7])
{
	ft_strcpy(arr[0], "ABCDEF");
	ft_strcpy(arr[1], "GH");
	ft_strcpy(arr[2], "IJ");
	ft_strcpy(arr[3], "KLM");
	ft_strcpy(arr[4], "NOP");
	ft_strcpy(arr[5], "QRS");
	ft_strcpy(arr[6], "TUV");
	ft_strcpy(arr[7], "W");
	ft_strcpy(arr[8], "X");
}

void	ft_strcpy(char *s1, char *s2)
{
	while (*s2 != '\0')
		*s1++ = *s2++;
	*s1 = '\0';
}

void	ft_get_knowledge_table(int *arr)
{
	arr[0] = 0x1824;
	arr[1] = 0x4182;
	arr[2] = 0x4281;
	arr[3] = 0x4812;
	arr[4] = 0x2184;
	arr[5] = 0x2814;
	arr[6] = 0x4128;
	arr[7] = 0x4218;
	arr[8] = 0x8124;
	arr[9] = 0x8214;
	arr[10] = 0x1842;
	arr[11] = 0x4821;
	arr[12] = 0x2841;
	arr[13] = 0x2481;
	arr[14] = 0x1284;
	arr[15] = 0x1482;
	arr[16] = 0x8142;
	arr[17] = 0x8241;
	arr[18] = 0x8412;
	arr[19] = 0x2418;
	arr[20] = 0x1428;
	arr[21] = 0x2148;
	arr[22] = 0x1248;
	arr[23] = 0x8421;
}
