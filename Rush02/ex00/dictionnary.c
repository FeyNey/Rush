/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionnary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 00:16:29 by acoste            #+#    #+#             */
/*   Updated: 2025/10/06 17:47:03 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionnary.h"

int	case_exist(char *nb, t_dico **dico)
{
	t_dico *temp;

	temp = *dico;
	while (temp != NULL)
	{
		if (ft_strcmp(nb, temp->first_part) == 0)
			return (ft_putstr(temp->second_part), 0);
		temp = temp->next;
	}
	return (1);
}

char **prep_tab(int i)
{
	int fill;
	char **tab;

	fill = 0;
	tab = malloc(sizeof(char *) * (i + 1));
	if (!tab)
		return (NULL);
	tab[i] = NULL;
	tab[0] = NULL;
	while (tab[fill])
	{
		tab[fill] = NULL;
		fill++;
	}
	return (tab);
}

char	*ft_strdup(char *src)
{
	char	*dupp;
	int	i;

	i = 0;
	dupp = ft_malloc(ft_strlen(src));
	while (src[i])
	{
		dupp[i] = src[i];
		i++;
	}
	dupp[i] = '\0';
	return (dupp);
}

char	*ft_strlcpy(char *nb, int size)
{
	int		i;
	char	*dupp;

	i = 0;
	dupp = ft_malloc(size);
	while (nb[i] && i < size)
	{
		dupp[i] = nb[i];
		i++;
	}
	dupp[i] = '\0';
	return (dupp);
}