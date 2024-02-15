/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:47:39 by mchampag          #+#    #+#             */
/*   Updated: 2024/02/14 23:05:59 by mchampag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	env_add_back(t_env *env, char *str)
{
	t_env	*new;
	t_env	*sec_last;
	t_env	*temp;

	if (str == NULL)
		return (false);
	new = malloc(sizeof(t_env));
	if (!new)
		return (false);
	new->content = ft_strdup(str);
	if (env == NULL)
	{
		env = new;
		return (true);
	}
	sec_last = lstsecondlast(env);
	temp = sec_last->next;
	sec_last->next = new;
	sec_last->next->next = temp;
	sec_last->next->next->next = NULL;
	return (true);
}

int	check_env(t_env *env, char *args)
{
	char	var_name[1024];
	char	env_name[1024];

	get_var_name(var_name, args);
	while (env && env->next)
	{
		get_var_name(env_name, env->content);
		if (ft_strcmp(var_name, env_name) == 0)
		{
			ft_memdel(env->content);
			env->content = ft_strdup(args);
			return (0);
		}
		env = env->next;
	}
	return (1);
}

static int	env_size(t_env *lst)
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
