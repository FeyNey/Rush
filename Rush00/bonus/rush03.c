/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 22:54:12 by acoste            #+#    #+#             */
/*   Updated: 2025/09/21 17:40:12 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_condition03(int x, int y, int i, int j)
{
	if (i == 1 && j == 1)
		ft_putchar('A');
	else if (i == y && j == 1)
		ft_putchar('A');
	else if (i == 1 && j == x)
		ft_putchar('C');
	else if (i == y && j == x)
		ft_putchar('C');
	else if (i == 1)
		ft_putchar('B');
	else if (i == y)
		ft_putchar('B');
	else if (j == 1)
		ft_putchar('B');
	else if (j == x)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush03(int x, int y)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i <= y)
	{
		while (j <= x)
		{
			ft_condition03(x, y, i, j);
			j++;
		}
		ft_putchar('\n');
		j = 1;
		i++;
	}
}
