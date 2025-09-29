/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:28:30 by acoste            #+#    #+#             */
/*   Updated: 2025/09/29 02:58:18 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int	err(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}

void free_tab(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	display(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			ft_putchar(tab[i][j]);
			ft_putstr("\t");
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	display_tab(char *tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		printf("tab[%i] = %c\n", i, tab[i]);
		i++;
	}
}

int	fill_tab(char **tab, char **argv, int i)
{
	int k;

	k = 0;
	*tab = (char *)malloc(sizeof(char) * 5);
	if (!(*tab))
		return (err("Malloc error\n"), 0);
	(*tab)[4] = '\0';
	while (k < 4)
	{
		(*tab)[k] = argv[k + (i * 4) + 1][0];
		k++;
	}
	return (0);
}

char **initialise_tab(char **argv)
{
	char **tab;
	int i;

	i = 0;
	tab = (char**)malloc(sizeof(char*) * (4 + 1));
	if (!tab)
		return (err("Malloc error\n"), (char **)NULL);
	tab[4] = 0;
	while (i < 4)
	{
		fill_tab(&tab[i], argv, i);
		i++;
	}
	// display(tab);
	return (tab);
}

void	ft_verif_arg(char **argv)
{
	(void)argv;
	//TODO
}

/*
tab[0][0]  Collomn top;

tab[1][0]	Collomn bottom;

tab[2][0]	Row Left;

tab[3][0]	Row Right;
*/



char **initialise_solv(char **tab)
{
	char **solv;
	int i;
	int j;

	i = ft_strlen(tab[0]);
	solv = (char **)malloc(sizeof(char *) * (i + 1));
	if (!solv)
		return(err("Malloc Error\n"), NULL);
	solv[i] = 0;
	i = 0;
	while (tab[i])
	{
		j = 0;
		solv[i] = (char *)malloc(sizeof(char) * (ft_strlen(tab[i]) + 1));
		if (!solv[i])
			return ((char **)NULL);
		solv[i][ft_strlen(tab[i])] = 0;
		while (tab[i][j])
		{
			solv[i][j] = '0';
			j++;
		}
		i++;
	}
	// display(solv);
	return (solv);
}

void	display_sky(char **tab, char **solv)
{
	ft_putstr("\nMy SkyScraper : \n\n");

	ft_putstr("\t");
	ft_putstr("\t");
	ft_putchar(tab[0][0]);
	ft_putstr("\t");
	ft_putchar(tab[0][1]);
	ft_putstr("\t");
	ft_putchar(tab[0][2]);
	ft_putstr("\t");
	ft_putchar(tab[0][3]);
	ft_putstr("\t\n");
	ft_putchar('\n');


	ft_putstr("\t");
	ft_putchar(tab[2][0]);
	ft_putstr("\t");
	ft_putchar(solv[0][0]);
	ft_putstr("\t");
	ft_putchar(solv[0][1]);
	ft_putstr("\t");
	ft_putchar(solv[0][2]);
	ft_putstr("\t");
	ft_putchar(solv[0][3]);
	ft_putstr("\t");
	ft_putchar(tab[3][0]);
	ft_putstr("\n");
	ft_putchar('\n');

	ft_putstr("\t");
	ft_putchar(tab[2][1]);
	ft_putstr("\t");
	ft_putchar(solv[1][0]);
	ft_putstr("\t");
	ft_putchar(solv[1][1]);
	ft_putstr("\t");
	ft_putchar(solv[1][2]);
	ft_putstr("\t");
	ft_putchar(solv[1][3]);
	ft_putstr("\t");
	ft_putchar(tab[3][1]);
	ft_putstr("\n");
	ft_putchar('\n');

	ft_putstr("\t");
	ft_putchar(tab[2][2]);
	ft_putstr("\t");
	ft_putchar(solv[2][0]);
	ft_putstr("\t");
	ft_putchar(solv[2][1]);
	ft_putstr("\t");
	ft_putchar(solv[2][2]);
	ft_putstr("\t");
	ft_putchar(solv[2][3]);
	ft_putstr("\t");
	ft_putchar(tab[3][2]);
	ft_putstr("\n");
	ft_putchar('\n');

	ft_putstr("\t");
	ft_putchar(tab[2][3]);
	ft_putstr("\t");
	ft_putchar(solv[3][0]);
	ft_putstr("\t");
	ft_putchar(solv[3][1]);
	ft_putstr("\t");
	ft_putchar(solv[3][2]);
	ft_putstr("\t");
	ft_putchar(solv[3][3]);
	ft_putstr("\t");
	ft_putchar(tab[3][3]);
	ft_putstr("\n");
	ft_putchar('\n');

	ft_putstr("\t");
	ft_putstr("\t");
	ft_putchar(tab[1][0]);
	ft_putstr("\t");
	ft_putchar(tab[1][1]);
	ft_putstr("\t");
	ft_putchar(tab[1][2]);
	ft_putstr("\t");
	ft_putchar(tab[1][3]);
	ft_putstr("\t\n");

}


/* 	while (i < 4)
	{
		solv[i][j] = '0' + i;
		i++;
	} */

void	fill_line_4(char **tab, char **solv, int i, int j)
{
	if (i == 0)
	{
		solv[0][j] = '1';
		solv[1][j] = '2';
		solv[2][j] = '3';
		solv[3][j] = '4';
	}
	if (i == 1)
	{
		solv[3][j] = '1';
		solv[2][j] = '2';
		solv[1][j] = '3';
		solv[0][j] = '4';
	}
	if (i == 2)
	{
		solv[j][0] = '1';
		solv[j][1] = '2';
		solv[j][2] = '3';
		solv[j][3] = '4';
	}
	if (i == 3)
	{
		solv[j][3] = '1';
		solv[j][2] = '2';
		solv[j][1] = '3';
		solv[j][0] = '4';
	}
	(void)tab;
}


void	fill_line_1(char **tab, char **solv, int i, int j)
{
	if (i == 0)
	{
		solv[0][j] = '4';
	}
	if (i == 1)
	{
		solv[3][j] = '4';
	}
	if (i == 2)
	{
		solv[j][0] = '4';
	}
	if (i == 3)
	{
		solv[j][3] = '4';
	}
	(void)tab;
}


void	place_forced_output(char **tab, char **solv, int i, int j)
{
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '4')
			{
				fill_line_4(tab, solv, i, j);
			}
 			if (tab[i][j] == '1')
			{
				fill_line_1(tab, solv, i, j);
			}
			j++;
		}
		i++;
	}
}

int	ft_place_at_column(char **solv, char count, int line, int j)
{
	int i;
	int found;

	i = 0;
	found = 0;
	while (solv[i][j] != '\0')
	{
		found = 0;
		while (i < 4)
		{
			if (solv[i][j] == count)
				found = 1;
			i++;
		}
		if (found == 0)
		{
			solv[line][j] = count;
		}
		j++;
		i = 0;
	}
	return (1);
}

int	ft_place_at_line(char **solv, char count, int i)
{
	int j;
	int found;

	while (solv[i])
	{
		j = 0;
		found = 0;
		while (solv[i][j])
		{
			if (count == solv[i][j])
			{
				found = 1;
			}
			j++;
		}
		if (found == 0)
			return (ft_place_at_column(solv, count, i, 0));
		i++;
	}
	return (0);
}

int	place_column_line(char**solv, int i, int j)
{
	char index;
	int count;

	index = '1';
	while (index <= '4')
	{
		count = 0;
		i = 0;
		while (solv[i])
		{
			j = 0;
			while (solv[i][j])
			{
				if (solv[i][j] == index)
					count++;
				j++;
			}
			i++;
		}
		if (count == 3)
			return (ft_place_at_line(solv, index, 0));
		index++;
	}
	return (0);
}

void	fill_column(char **solv, int line, int j)
{
	int result;
	int index;

	result = 0;
	while (solv[line][j])
	{
		result += (solv[line][j] - '0');
		if (solv[line][j] == '0')
		{
			index = j;
		}
		j++;
	}
	solv[line][index] = 10 - result + '0';
}

int	fill_column_line(char **solv, int i, int j)
{
	int	found;

	found = 0;
	while (solv[i])
	{
		found = 0;
		j = 0;
		while (solv[i][j])
		{
			if (solv[i][j] != '0')
			{
				found++;
			}
			j++;
		}
		if (found == 3)
			return (fill_column(solv, i, 0), 1);
		i++;
	}
	return (0);
}

int	place_pre_forced_output(char **solv)
{
	int k;
	int l;
	int a;

	k = 1;
	l = 1;
	a = 0;
	while ((k == 1 || l == 1) && (a < 100))
	{
		k = place_column_line(solv, 0, 0);
		l = fill_column_line(solv, 0, 0);
		a++;
	}
	if (a == 100)
		return (-1);
	return(0);
}

int	verif_solv(char **solv, int i, int j)
{
	int id;
	int nb_verif;

	id = 0;
	nb_verif = 0;
	while(id < 4)
	{
		i = 0;
		while (solv[i])
		{
			j = 0;
			nb_verif = 0;
			while (solv[i][j])
			{
				if ((solv[i][id] == solv[i][nb_verif]) && (id != nb_verif) \
					&& solv[i][id] != '0' && solv[i][nb_verif] != '0')
					return (ft_putstr("EXIT VALUE \n"), -1);
				j++;
				nb_verif++;
			}
			i++;
		}
		id++;
	}
	return (0);
}

char **ft_strrdup(char **dupp)
{
	char **nsolv;
	int i;
	int j;

	i = 0;
	nsolv = initialise_solv(dupp);
	while (dupp[i])
	{
		j = 0;
		while (dupp[i][j])
		{
			nsolv[i][j] = dupp[i][j];
			j++;
		}
		i++;
	}
	return (nsolv);
}


int	backking(char **tab, char**solv, int i, int j)
{
	char **nsolv;

	while ()
	{
		nsolv = ft_strrdup(solv);
// double tableau avec des 0 et des 1 pour savoir si ma case est pres rempli ou pas;

		if (ft_verif_nsolv(tab, solv, i, j) == 0)
		{
			display_tab(nsolv);
			free_tab(nsolv);
			return (0);
		}
		free_tab(nsolv);
	}
}

int	solver(char **tab)
{
	char **solv;

	solv = initialise_solv(tab);

	place_forced_output(tab, solv, 0, 0);
	ft_putstr("\t Forced Output");
	display_sky(tab, solv);
	if (place_pre_forced_output(solv) == -1)
		return (ft_putstr("Error\n"), free_tab(solv), 0);
	ft_putstr("\n\t Pre Forced Output");
	display_sky(tab, solv);
	ft_putstr("\n\n");
	display(solv);
	if (verif_solv(solv, 0, 0) == -1)
	{
		err("Error\n");
		return (0);
	}
	backking(tab, solv, 0, 0);
	free_tab(solv);
	return (0);
}

int	main(int argc, char **argv)
{
	char **tab;

	if (argc != 17)
		return (err("Error\n"));
	else
	{
		ft_verif_arg(argv);
		tab = initialise_tab(argv);
		solver(tab);
	}
	free_tab(tab);
}
