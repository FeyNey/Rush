/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 00:06:22 by acoste            #+#    #+#             */
/*   Updated: 2025/10/06 17:48:09 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionnary.h"

char	*found_hundred(t_dico **dico)
{
		return (is_in_my_book(dico, "100"));
}

void	aff_list(t_dico *dico)
{
	int i;
	t_dico *temp;

	i = 0;
	temp = dico;
	while (temp != NULL)
	{
		printf("Node nbr %i :\n", i);
		printf("Dico first content : %s\n", (temp)->first_part);
		printf("Dico second content : %s\n", (temp)->second_part);

		temp = temp->next;
		i++;
	}
}

void	free_list(t_dico **dico)
{
	t_dico *temp;

	temp = (*dico);
	if ((*dico) == NULL)
		return ;
	while ((*dico)->next != NULL)
	{
		temp = (*dico)->next;
		free((*dico)->first_part);
		free((*dico)->second_part);
		free((*dico));
		((*dico) = temp);
	}
	free((*dico)->first_part);
	free((*dico)->second_part);
	free((*dico));
}


int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] == s2[i] && s1[i] && s2[i])
	{
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
	{
		return (0);
	}
	return (1);
}

char	*ft_strjoin_without_nl(char *stash, char *buffer)
{
	char	*stock;
	int		i;
	int		j;

	i = ft_strlen(stash) + ft_strlen(buffer);
	stock = ft_malloc(i);
	i = -1;
	if (stash)
	{
		while (stash[++i])
		{
			if (stash[i] == '\n')
			{
				stock[i++] = ' ';
				break;
			}
			stock[i] = stash[i];
		}
	}
	j = -1;
	if (buffer)
	{
		while (buffer[++j])
		{
			if (buffer[j] == '\n')
				break;
			stock[i + j] = buffer[j];
		}
		stock[i + j] = '\0';
	}
	if (stash)
		free(stash);

	printf("My joined stash (ft_strjoin _wn) = %s\n", stock);
	return (stock);
}


char	*parse_nb(char *nb)
{
	while (nb && *nb == '0' && *(nb + 1))
		nb++;
	return (nb);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * (-1);
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb + '0');
}

int	err_nbr(char *str, int e)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	ft_putnbr(e);
	write(1, "\n", 1);
	return (1);
}

int	err(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
