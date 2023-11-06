/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:13:52 by adube             #+#    #+#             */
/*   Updated: 2023/11/06 11:26:25 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_var_name(char *dest, char *src)
{
	int	i;

	i = 0;
	while(src[i] && src[i] != '=' && ft_strlen(src) < BUFFER_SIZE)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return(dest);
}

int	check_env(t_env *env, char *args)
{
	char	var_name[1024];
	char	env_name[1024];
	
	get_var_name(var_name, args);
	while(env && env->next)
	{
		get_var_name(env_name, env->content);
		if(ft_strcmp(var_name, env_name) == 0)
		{
			ft_memdel(env->content);
			env->content = ft_strdup(args);
			return (0);
		}
		env = env->next;
	}
	return (1);
}

t_env	*lstlast(t_env *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

bool	env_add_back(t_env *env, char *str)
{
	t_env	*new;
	t_env	*last;
	
	if (str == NULL)
		return (false);
	new = (t_env *)str;
	if (env == NULL)
	{
		env = new;
		return (true);
	}
	last = lstlast(env);
	last->next = new;
	last->next->next = NULL;
	return (true);
}

int	ft_export(char **cmd, t_env *env)
{
	//mettre dans parsing
	if (cmd[1] == NULL || cmd[2])
	{
		ft_putendl_fd("export needs to have 1 argument", 2);
		return (1);
	}
	if (check_env(env, cmd[1]) == 0)
		return (0);
	else if (env_add_back(env, cmd[1]) == true)
			return (0);
	return (1);
}
