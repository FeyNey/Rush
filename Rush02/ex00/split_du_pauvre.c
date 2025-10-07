/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_du_pauvre.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:49:02 by acoste            #+#    #+#             */
/*   Updated: 2025/10/07 01:26:10 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionnary.h"

void	write_words(char *tab, char*s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0' && s[i] != ' ')
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
}

void	write_words2(char *tab, char*s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
}

void	tab_split(char **tab, char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j] != c && str[j] != ' ' && str[j] != '\0')
		j++;
	tab[0] = malloc(sizeof(char) * (j + 1));
	write_words(tab[0], str, c);
	// printf("tab [1] = %s   ,   ", tab[0]);
	if (str[j] != c)
		while (str[j] != c && str[j])
			j++;
	while ((str[j] == c || str[j] == ' ') && str[j] != '\0')
		j++;
	i = j;
	while (str[i] != '\0')
		i++;
	tab[1] = malloc(sizeof(char) * i - j + 1);
	write_words2(tab[1], str + j, c);
	// printf("tab [1] = %s", tab[1]);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char **split_du_pauvre(char *str, char c)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * (2 + 1));
	if (tab == 0)
		return (0);
	tab[2] = 0;
	tab_split(tab, str, c);
	return (tab);
}