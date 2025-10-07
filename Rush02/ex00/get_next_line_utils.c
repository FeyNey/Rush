/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:02:04 by acoste            #+#    #+#             */
/*   Updated: 2025/10/07 01:01:41 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionnary.h"

char	*ft_realloc(char *stock, int size)
{
	char	*str;
	int		i;

	if (size <= ft_strlen(stock))
		return (printf("Bleme\n"), NULL);
	str = ft_calloc(size);
	while (stock[i])
	{
		str[i] = stock[i];
		i++;
	}
	if (stock)
		free(stock);
	return (str);
}


char	*ft_calloc(int height)
{
	int i;
	char	*new;

	i = 0;
	new = malloc(sizeof(char) * (height + 1));
	if (!new)
		return (NULL);
	while (i <= height)
	{
		new[i] = '\0';
		i++;
	}
	return (new);
}

char	*ft_malloc(int height)
{
	char	*new;

	new = malloc(sizeof(char) * (height + 1));
	if (!new)
		return (NULL);
	new[height] = '\0';
	return (new);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_search(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
