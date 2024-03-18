/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremovenode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:47:11 by mchampag          #+#    #+#             */
/*   Updated: 2024/03/17 20:48:12 by mchampag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremovenode(t_list **lst, t_list *node_to_remove, void (*del)(void *))
{
	t_list	*tmp;

	tmp = *lst;
	if (tmp == NULL || node_to_remove == NULL)
		return ;
	if (tmp == node_to_remove)
	{
		*lst = tmp->next;
		del(node_to_remove->content);
		node_to_remove->content = NULL;
		free(node_to_remove);
		return ;
	}
	while (tmp->next != NULL)
	{
		if (tmp->next == node_to_remove)
		{
			tmp->next = node_to_remove->next;
			del(node_to_remove->content);
			node_to_remove->content = NULL;
			free(node_to_remove);
			return ;
		}
		tmp = tmp->next;
	}
}
// a refaire