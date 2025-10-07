/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:54:17 by acoste            #+#    #+#             */
/*   Updated: 2025/10/07 04:12:36 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionnary.h"

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
		*ns = t2;
		printf("ns = %s\n", *ns);
		return (1);
	}
	if (cpy)
		free(cpy);
	if (nb[0] == '0')
		return (0);
	printf("c1 == %c", c1);
	while (temp != NULL)
	{
		if (temp->first_part[0] == c1 && temp->first_part[1] == '\0')
		{
			str = temp->second_part;
			*ns = ft_strjoin_without_nl(str, found_hundred(dico));
			printf("\n*ns after join = %s\n", *ns);

		}

		temp = temp->next;
	}
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
		printf("*t2 = %s\n", t2);
		if (cpy)
			free(cpy);
		*ns = t2;
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
			// *ns = ft_strdup(*ns);
			printf("|| search book 2 ||\n*ns = %s", *ns);
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
		*ns = t2;
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
			// *ns = ft_strdup(*ns);
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
		str = ft_strdup(is_in_my_book(dico, cpy));
		if (cpy)
			free(cpy);
		printf("str = %s\n", str);
		return (str);
	}
	else
	{
		if (diff == 2)
		{
			printf("||| DIFF = 2 |||   ");
			search_book_index2(nb[0], nb, dico, &temp);
			search_book_index2(nb[0], nb, dico, &str);
			// ft_strdup(str);
			search_book_index1(nb[1], &nb[1], dico, &temp);
			str = ft_strjoin_without_nl(str, temp);
			if (cpy)
				free(cpy);
			// free(temp);
			printf(" ->  str = %s\n", str);
			return (str) ;
		}
		if (diff == 1)
		{
			printf("   DIFF = 1 |||   ");
			search_book_index1(nb[0], &nb[0], dico, &temp);
			str = ft_strdup(temp);
		}
	}
	if (cpy)
		free(cpy);
	printf("str = %s\n", str);
	return (str);
}

char	*next_words(char *nb, t_dico **dico)
{
	// int	i;
	char	*str;
	char	*temp;

	// i = 0;
	str = NULL;
	printf("nb = %s\n", nb);
	if (search_book_index3(nb[0], nb, dico, &temp) == 1)
	{
		// printf("sorti index3 = %s\n", temp);
		return (ft_strjoin_without_nl(str, temp));
	}
	nb++;
	// printf("temp 1 = %s\n", temp);
	str = ft_strjoin_without_nl(str, temp);
	// printf("STR 1 = %s\n", str);
	if (search_book_index2(nb[0], nb, dico, &temp) == 1)
		return (ft_strjoin_without_nl(str, temp));
	// printf("temp 2 = %s\n", temp);
	str = ft_strjoin_without_nl(str, temp);
	// printf("STR 2 = %s\n", str);
	nb++;
	if (search_book_index1(nb[0], nb, dico, &temp) == 1)
		return (ft_strjoin_without_nl(str, temp));
	// printf("temp 3 = %s\n", temp);
	str = ft_strjoin_without_nl(str, temp);
	// printf("STR 3 = %s\n", str);

	return (str);
}

char	*get_suffixe(int i, t_dico **dico)
{
	int count;
	int	r;
	t_dico	*temp;

	if (i == 1)
		return (0);
	temp = *dico;
	while (temp)
	{
		count = 1;
		r = 0;
		if (temp->first_part[0] == '1')
		{
			while (temp->first_part[count])
			{
				if (temp->first_part[count] == '0')
					r++;
				count++;
			}
		}
		if (r == ((i - 1) * 3))
			return (temp->second_part);
		temp = temp->next;
	}
	return (0);
}

char	*ft_no_new_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\0')
			str[i] = '\0';
		i++;
	}
	return (str);
}

void	ft_putsuffixe(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		write(1, &str[i], 1);
		i++;
	}
}


int	compose_number(char *nb, t_dico **dico)
{
	int	i;
	int len;
	int diff;
	char **answer;
	int index;
	char	*str;

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
	// printf("Answer [0] = %s\n", answer[0]);
	while (index < i)
	{
		// if (is_in_my_book(dico, nb)) // gerer exception 40 000 + 5369 : defined (45369)
		answer[index] = next_words(nb, dico);


		printf("Answer [%i] = %s\n", index, answer[index]);
		index++;
		if (index < i)
			nb = nb + 3;
	}
	index = 0;
	printf("THERE IT IS  <<< i = %i >>>\n", index);
	printf("Answer[index] == %s\n", answer[index]);
	while (answer[index])
	{
		answer[index] = ft_no_new_line(answer[index]);
		index++;
	}
	index = 0;
	while (i > 0 && answer[index])
	{
		ft_putstr(answer[index]);
		if (!answer[index + 1])
			break;
		ft_putchar(' ');
		str = get_suffixe(i, dico);
		if (str)
			ft_putsuffixe(str);
		ft_putchar(' ');
		// ajoute le suffixe correspondant
		//recommence a l'index --


		// nb + diff;
		index++;
		i--;
	}

	free_split(answer);
	return (0);
}