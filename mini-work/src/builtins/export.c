/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:13:52 by adube             #+#    #+#             */
/*   Updated: 2024/02/02 09:39:03 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_var_name(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != '=' && ft_strlen(src) < BUFFER_SIZE)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
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

t_env	*lstsecondlast(t_env *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

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

int	ft_export(char **cmd, t_env *env)
{
	int		i;
	t_env 	*temp;
	int		flag;
	
	i = 0;
	while (cmd[++i])
	{
		flag = 0;
		temp = env;
		if (check_env(temp, cmd[i]) == 0)
 			flag = 1;
 		else if (flag != 1)
 			env_add_back(temp, cmd[i]);
		env = temp;
	}
	return (0);
}