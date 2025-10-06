/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 00:06:19 by acoste            #+#    #+#             */
/*   Updated: 2025/10/06 17:51:55 by acoste           ###   ########.fr       */
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

int	search_book_index3(char c1, char *nb, t_dico **dico, char **ns)
{
	t_dico *temp;
	char	*cpy;
	char	*t2;
	char	*str;

	str	=	NULL;
	temp = *dico;
	cpy = ft_strlcpy(nb, 3);
	if (is_in_my_book(dico, cpy) != NULL)
	{

		t2 = is_in_my_book(dico, cpy);
		if (cpy)
			free(cpy);
		*ns = ft_strdup(t2);
		return (1);
	}
	printf("IM HERE\n");
	if (cpy)
		free(cpy);
	if (nb[0] == '0')
		return (0);
	printf("c1 == %c", c1);
	while (temp != NULL)
	{
		// printf ("temp firstpart[0] = %c     ,   ", temp->first_part[0]);
		// printf ("temp firstpart[1] = %c\n", temp->first_part[1]);
		if (temp->first_part[0] == c1 && temp->first_part[1] == '\0')
		{
			str = temp->second_part;
			str = ft_strjoin_without_nl(str, found_hundred(dico));
			printf("\nstr after join = %s\n", str);
		}

		temp = temp->next;
	}
	printf("IM HERE\n");
	return (0);
}

int	search_book_index2(char c1, char *nb, t_dico **dico, char **ns)
{
	t_dico *temp;
	char	*cpy;
	char	*t2;

	temp = *dico;
	cpy = ft_strlcpy(nb, 2);
	if (is_in_my_book(dico, cpy) != NULL)
	{
		t2 = is_in_my_book(dico, cpy);
		if (cpy)
			free(cpy);
		*ns = ft_strdup(t2);
		return (1);
	}
	if (cpy)
		free(cpy);
	if (nb[0] == '0')
		return (0);
	while (temp != NULL)
	{
		if (temp->first_part[0] == c1 && temp->first_part[1] == '0')
		{
			*ns = temp->second_part;
			return (0);
		}
		temp = temp->next;
	}
	return (0);
}

int	search_book_index1(char c1, char *nb, t_dico **dico, char **ns)
{
	t_dico *temp;
	char	*cpy;
	char	*t2;

	temp = *dico;
	cpy = ft_strlcpy(nb, 1);
	if (is_in_my_book(dico, cpy) != NULL)
	{
		t2 = is_in_my_book(dico, cpy);
		if (cpy)
			free(cpy);
		*ns = ft_strdup(t2);
		return (1);
	}
	if (cpy)
		free(cpy);
	if (nb[0] == '0')
		return (0);
	while (temp != NULL)
	{
		if (temp->first_part[0] == c1 && !temp->first_part[1])
		{
			*ns = temp->second_part;
			return (0);
		}
		temp = temp->next;
	}
	return (0);
}

char	*first_nb(int diff, char *nb, char *str, t_dico **dico)
{
	char	*cpy;
	char	*temp;

	cpy = ft_strlcpy(nb, diff);
	if (is_in_my_book(dico, cpy) != NULL)
	{
		printf("DIFF FOUND\n");
		str = ft_strdup(is_in_my_book(dico, cpy));
		if (cpy)
			free(cpy);
		return (str);
	}
	else
	{
		if (diff == 2)
		{
			printf("DIFF = 2\n");
			search_book_index2(nb[0], nb, dico, &temp);
			search_book_index2(nb[0], nb, dico, &str);
			ft_strdup(str);
			search_book_index1(nb[1], &nb[1], dico, &temp);
			ft_strjoin_without_nl(str, temp);
			str = temp;
			if (cpy)
				free(cpy);
			// free(temp);
			return (str) ;
		}
		if (diff == 1)
		{
			printf("DIFF = 1\n");
			search_book_index1(nb[0], &nb[0], dico, &temp);
			str = ft_strdup(temp);
		}
	}
	if (cpy)
		free(cpy);
	printf("My second word is %s\n", str);
	return (str);
}

char	*next_words(char *nb, t_dico **dico)
{
	int	i;
	char	*str;
	char	*temp;

	i = 0;
	str = NULL;
	printf("nb = %s\n", nb);
	if (search_book_index3(nb[0], nb, dico, &temp) == 1)
		return (ft_strjoin_without_nl(str, temp));
	printf("temp 1 = %s\n", temp);
	str = ft_strjoin_without_nl(str, temp);
	printf("STR 1 = %s\n", str);
	if (search_book_index2(nb[1], nb, dico, &temp) == 1)
		return (ft_strjoin_without_nl(str, temp));
	printf("temp 2 = %s\n", temp);
	str = ft_strjoin_without_nl(str, temp);
	printf("STR 2 = %s\n", str);
	if (search_book_index1(nb[2], nb, dico, &temp) == 1)
		return (ft_strjoin_without_nl(str, temp));
	printf("temp 3 = %s\n", temp);
	str = ft_strjoin_without_nl(str, temp);
	printf("STR 3 = %s\n", str);

	return (str);
}

int	compose_number(char *nb, t_dico **dico)
{
	int	i;
	int len;
	int diff;
	char **answer;
	int index;

	i = ft_packages(nb);
	len = ft_strlen(nb);
	answer = prep_tab(i);
	diff = len % 3;
	index = 0;
	if (diff == 1 || diff == 2)
	{
		printf("THERE IS A DIFF\n");
		answer[0] = first_nb(diff, nb, answer[0], dico);
		index++;
		nb = nb + diff;
	}
	else
		printf("there is no diff\n");
	printf("Answer [0] = %s\n", answer[index - 1]);
	while (index < i)
	{
		answer[index] = next_words(nb, dico);


		printf("Answer [%i] = %s\n", index, answer[index]);
		index++;
		if (index < i)
			nb = nb + 3;
	}
	while (i != 0)
	{
		// answer(nb, i, dico);
		//decoupe un packet des 3 plus haut,
		//leurs donne une valeur -> (verifie si existe d'abord) ensuite dans le tableau
		// ajoute le suffixe correspondant
		//recommence a l'index --


		// nb + diff;
		i--;
	}
	(void)nb;
	(void)dico;
	// free_split(answer);
	return (0);
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
		chain = split_du_pauvre(str, ':');
		node = ft_lstnew(chain[0], chain[1]);
		ft_lstadd_back(dico, node);
		free(chain);
		if (str)
			free(str);
	}
	// aff_list(*dico);
	nb = parse_nb(nb);
	associate_number(nb, dico);


	// free_list(dico);
	return (0);
}

int	main(int argc, char **argv)
{
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
