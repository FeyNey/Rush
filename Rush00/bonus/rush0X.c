/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush0X.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 22:55:40 by acoste            #+#    #+#             */
/*   Updated: 2025/09/21 01:54:21 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	ft_putchar(char c);

void	ft_putstr(char *str);

void	ft_condition0x(int *pos, int i, int j, char *caract)
{
	if (i == 1 && j == 1)
		ft_putchar(caract[0]);
	else if (i == pos[1] && j == 1)
		ft_putchar(caract[6]);
	else if (i == 1 && j == pos[0])
		ft_putchar(caract[2]);
	else if (i == pos[1] && j == pos[0])
		ft_putchar(caract[8]);
	else if (i == 1)
		ft_putchar(caract[1]);
	else if (i == pos[1])
		ft_putchar(caract[7]);
	else if (j == 1)
		ft_putchar(caract[3]);
	else if (j == pos[0])
		ft_putchar(caract[5]);
	else
		ft_putchar(caract[4]);
}

void	rush0x(int x, int y, char **arg)
{
	int		i;
	int		j;
	int		dir[2];
	char	tab[9];

	dir[0] = x;
	dir[1] = y;
	j = 0;
	while (arg[j++ + 4])
	{
		tab[j - 1] = arg[j + 3][0];
	}
	i = 1;
	j = 1;
	while (i <= y)
	{
		while (j <= x)
		{
			ft_condition0x(dir, i, j, tab);
			j++;
		}
		ft_putchar('\n');
		j = 1;
		i++;
	}
}
