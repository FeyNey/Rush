/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 23:01:42 by acoste            #+#    #+#             */
/*   Updated: 2025/10/05 15:29:53 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionnary.h"

char	*ft_strjoin(char *stash, char *buffer)
{
	char	*stock;
	int		i;
	int		j;

	i = ft_strlen(stash) + ft_strlen(buffer);
	stock = ft_malloc(i);
	i = -1;
	while (stash[++i])
		stock[i] = stash[i];
	j = -1;
	while (buffer[++j])
		stock[i + j] = buffer[j];
	if (stash)
		free(stash);
	return (stock);
}

char	*read_file(int fd, char *stash)
{
	char	*buffer;
	int		i;
	int		j;

	if (!stash)
		stash = ft_malloc(0);
	buffer = ft_malloc(BUFFER_SIZE);
	i = -1;
	j = 1;
	while (j > 0 && i == -1)
	{
		j = read(fd, buffer, BUFFER_SIZE);
		if (j == -1)
			return (free(buffer), NULL);
		buffer[j] = '\0';
		i = ft_search(buffer, '\n');
		stash = ft_strjoin(stash, buffer);
		if (i > -1)
			break ;
	}
	free(buffer);
	return (stash);
}

char	*ft_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_next_line(char *stash)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	line = ft_malloc(ft_strlen(stash) - i - 1);
	i++;
	j = 0;
	while (stash[i])
	{
		line[j] = stash[i];
		i++;
		j++;
	}
	free(stash);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	stash = read_file(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_line(stash);
	stash = ft_next_line(stash);
	return (line);
}