/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:50:46 by acoste            #+#    #+#             */
/*   Updated: 2025/10/06 17:52:00 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionnary.h"

int	verif_arg(char *str)
{
	int	i;

	i = 0;
	if (!str[0])
		return (1);
	if ((str[0] == '+' || str[0] == '-') && str[1])
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	verif_line(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (1);
	if (str[i] == '\n')
		return (0);
	if (str[i] < '0' || str[i] > '9')
		return (2);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ')
		i++;
	if (str[i] != ':')
		return (3);
	else
		i++;
	while (str[i] == ' ')
		i++;
	if (str[i] < 32 || str[i] == 127)
		return (4);
	while (str[i] >= 32 && str[i] <= 126)
		i++;
	if (str[i] != '\n' && str[i] != '\0')
		return (5);
	return (0);
}

int	parse_dictionnary()
{
	int	fd;
	char	*str;
	int	i;

	i = 1;
	str = "1";
	fd = open("numbers.dict", O_RDONLY);
	if (fd < 0)
		return (err("Could not open file\n"));
	while (str != NULL)
	{
		str = get_next_line(fd);
		// printf("result = %s", str);
		if (str != NULL)
			if (verif_line(str))
				return (free(str), err_nbr("Wrong format line ", i));
		if (str)
			free(str);
		i++;
	}
	close(fd);
	return (0);
}