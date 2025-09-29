/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 17:18:31 by acoste            #+#    #+#             */
/*   Updated: 2025/09/23 17:35:26 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putchar(char c);

void	ft_putstr(char *str);

int		err(char *str);

void	rush00(int x, int y);

void	rush01(int x, int y);

void	rush02(int x, int y);

void	rush03(int x, int y);

void	rush04(int x, int y);

void	rush0x(int x, int y, char **arg);

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	if (str1[i] != str2[i])
		return (1);
	return (0);
}

size_t	ft_atoz(char *str)
{
	int		i;
	size_t	res;

	i = 0;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (err("value is negative, it should be positive\n") \
					, -1);
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (err("invalid caracter try a number\n"), -1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (err("other caracters after the number\n"), -1);
	if (res > 2147483647)
		return (err("int max exceded\n"), -1);
	return (res);
}

int	verif_arg(char **argv)
{
	int	i;

	i = 4;
	if ((ft_strcmp(argv[1], "Rush00")) && (ft_strcmp(argv[1], "Rush01")) \
		&& (ft_strcmp(argv[1], "Rush02")) && (ft_strcmp(argv[1], "Rush03")) \
		&& (ft_strcmp(argv[1], "Rush04") && ft_strcmp(argv[1], "Rush0X")))
	{
		err("Wrong Rush argument, ");
		return (err(argv[1]), err(" is not selectionable\n"));
	}
	if ((int)ft_atoz(argv[2]) == -1)
		return (err(argv[2]), err(" is not a valid number, x invalid value"));
	if ((int)ft_atoz(argv[3]) == -1)
		return (err(argv[3]), err(" is not a valid number, y invalid value"));
	while (argv[i])
	{
		if (argv[i][1] != '\0')
			return (err("Too many carateres in argument "), err(argv[i]), \
					err("\n"));
		i++;
	}
	return (0);
}

void	select_rush(char *rush_nbr, char **arg)
{
	if (!(ft_strcmp(rush_nbr, "Rush00")))
		rush00((int)ft_atoz(arg[2]), (int)ft_atoz(arg[3]));
	if (!(ft_strcmp(rush_nbr, "Rush01")))
		rush01((int)ft_atoz(arg[2]), (int)ft_atoz(arg[3]));
	if (!(ft_strcmp(rush_nbr, "Rush02")))
		rush02((int)ft_atoz(arg[2]), (int)ft_atoz(arg[3]));
	if (!(ft_strcmp(rush_nbr, "Rush03")))
		rush03((int)ft_atoz(arg[2]), (int)ft_atoz(arg[3]));
	if (!(ft_strcmp(rush_nbr, "Rush04")))
		rush04((int)ft_atoz(arg[2]), (int)ft_atoz(arg[3]));
	if (!(ft_strcmp(rush_nbr, "Rush0X")))
		rush0x((int)ft_atoz(arg[2]), (int)ft_atoz(arg[3]), arg);
}

int	main(int argc, char **argv)
{
	if (argc == 13)
	{
		if (ft_strcmp(argv[1], "Rush0X") == 1)
			return (err("Wrong Rush argument :"), err(argv[1]), err("\n"));
		if (verif_arg(argv))
			return (err("Error argument\n"), 1);
		select_rush(argv[1], argv);
		return (0);
	}
	else if (argc != 4)
	{
		ft_putstr("Not enought argument\n");
		return (ft_putstr("  Try <Rush0x> (x between 0 and 3) <x> <y> or\n"), \
				ft_putstr("  Try <Rush0X> <x> <y> <a> <b> <c> <d> "), \
				ft_putstr("<e> <f> <g> <h> <i> where\n"), \
				ft_putstr("\t<a> <b> <c>\n"), \
				ft_putstr("\t<d> <e> <f>\n"), \
				ft_putstr("\t<g> <h> <i>\n"), 1);
	}
	if (ft_strcmp(argv[1], "Rush0X") == 0)
		return (err("Rush0X not enought arguments\n"));
	if (verif_arg(argv))
		return (err("Error argument\n"), 1);
	else
		select_rush(argv[1], argv);
}
