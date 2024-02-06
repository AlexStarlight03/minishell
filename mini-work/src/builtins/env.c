/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:14:19 by adube             #+#    #+#             */
/*   Updated: 2024/02/06 11:51:28 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	env_size(t_env *lst)
{
	int	size;

	size = 1;
	if (!lst)
		return (0);
	while (lst -> next)
	{
		size++;
		lst = lst -> next;
	}
	return (size);
}

char	*env_str(t_env *list)
{
	char	*env;
	int		i;
	int		j;

	if (!(env = malloc(sizeof(char) * env_size(list) + 1)))
		return (NULL);
	i = 0;
	while (list && list->next != NULL)
	{
		if (list->content != NULL)
		{
			j = 0;
			while (list->content[j])
			{
				env[i] = list->content[j];
				i++;
				j++;
			}
		}
		if (list->next->next != NULL)
			env[i++] = '\n';
		list = list->next;
	}
	env[i] = '\0';
	return (env);
}


int	ft_env(t_env *env)
{
	while (env && env->next != NULL)
	{
		ft_putendl_fd(env->content, 1);
		env = env->next;
	}
	if (env)
		ft_putendl_fd(env->content, 1);
	return (0);
}