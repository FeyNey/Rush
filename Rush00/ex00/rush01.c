/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 22:29:08 by acoste            #+#    #+#             */
/*   Updated: 2025/09/21 17:20:48 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_condition(int x, int y, int i, int j)
{
	if (i == 1 && j == 1)
		ft_putchar('/');
	else if (i == y && j == 1)
		ft_putchar('\\');
	else if (i == 1 && j == x)
		ft_putchar('\\');
	else if (i == y && j == x)
		ft_putchar('/');
	else if (i == 1 || i == y)
		ft_putchar('*');
	else if (j == 1 || j == x)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i <= y)
	{
		while (j <= x)
		{
			ft_condition(x, y, i, j);
			j++;
		}
		ft_putchar('\n');
		j = 1;
		i++;
	}
}
