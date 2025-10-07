/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 00:06:19 by acoste            #+#    #+#             */
/*   Updated: 2025/10/07 03:36:57 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionnary.h"

char	*is_in_my_book(t_dico **dico, char *nb)
{
	t_dico *temp;

	temp = *dico;

	while (temp != NULL)
	{
		if (ft_strcmp(nb, temp->first_part) == 0)
		{
			return (temp->second_part);
		}
		temp = temp->next;
	}
	return (NULL);
}

int	ft_packages(char *nb)
{
	int	i;

	i = (ft_strlen(nb));
	if (i % 3 != 0)
	{
		i = i / 3;
		i += 1;
	}
	else
		i = i / 3;
	return (i);
}

int	associate_number(char *nb, t_dico **dico)
{
	if (case_exist(nb, dico) == 0)
		return (0);
	if (compose_number(nb, dico) == 0)
		return (0);
	return (1);
}

int	translate_dictionnary(char *nb)
{
	t_dico	**dico;
	t_dico	*test;


	char *str;
	int	fd;
	char **chain;
	t_dico	*node;

	int i;

	i = 0;

	test = NULL;
	dico = &test;
	str = "initialized";
	fd = open("numbers.dict", O_RDONLY);
	if (fd < 0)
		return (err("Could not open file\n"));
	while (str != NULL)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break;
		if (str[0] >= '0' && str[0] <= '9')
		{
			chain = split_du_pauvre(str, ':');
			node = ft_lstnew(chain[0], chain[1]);
			ft_lstadd_back(dico, node);
			free(chain);
		}
		if (str)
			free(str);
		i++;
	}
	// aff_list(*dico);
	nb = parse_nb(nb);
	associate_number(nb, dico);


	free_list(dico);
	return (0);
}

int	main(int argc, char **argv)
{
	system("clear");
	if (argc == 2)
	{
		if (verif_arg(argv[1]))
			return (err("Error\n"));
		if (parse_dictionnary())
			return (err("Error\n"));
		translate_dictionnary(argv[1]);
		return (0);
	}
	if (argc == 3)
	{
		if (verif_arg(argv[2]))
			return (err("Error\n"));
		//try open dictionnary

		return (0);
	}
	else
		return (err("Error\n"));
}
