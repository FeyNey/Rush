/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 02:02:45 by acoste            #+#    #+#             */
/*   Updated: 2025/10/05 17:30:32 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionnary.h"

t_dico	*ft_lstnew(void *fp, void *sp)
{
	t_dico	*node;

	node = (t_dico *)malloc(sizeof(t_dico));
	if (node == 0)
		return (NULL);
	node->first_part = fp;
	node->second_part = sp;
	node->next = NULL;
	return (node);
}
void	ft_lstadd_back(t_dico **lst, t_dico *new)
{
	t_dico *temp;

	temp = NULL;
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}