/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <marvin@42quebec.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:25:22 by adube             #+#    #+#             */
/*   Updated: 2022/11/28 17:43:15 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*temp;
	void	*content;

	newlist = 0;
	temp = 0;
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		temp = ft_lstnew(content);
		if (temp == NULL)
		{
			ft_lstclear(&newlist, del);
			free(content);
			return (NULL);
		}
		ft_lstadd_back(&newlist, temp);
		lst = lst->next;
	}
	return (newlist);
}
