/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:13:52 by adube             #+#    #+#             */
/*   Updated: 2023/10/27 11:09:30 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

//mettre dans libft -- ajouter return bool
bool	ft_str_in(char *big, char *little, char limit)
{
	int	i;

	if (big == NULL || little == NULL)
		return (false);
	i = 0;
	while (big[i] != limit && little[i])
	{
		while (big[i] == little[i] && little[i])
			i++;
		if (big[i] == limit && little[i] == '\0')
			return (true);
	}
	return (false);
}

int	*ft_tab_check(t_env *env, char *args)
{
	int	i;

	i = -1;
	while (env && env->next != NULL)
	{
		if (ft_str_in(env->content, str, limit))
			return (env);
		env =  env->next;
	}
	if (ft_str_in(env->content, str, limit))
			return (env);
	return (NULL);
}

bool	ft_lstreplace(t_env *ptr_env, void *str)
{
	if (ptr_env == NULL || str == NULL)
		return (false);
	ft_memdel(ptr_env->content);
	ptr_env->content = ft_strdup(str);
	return (0);
}

int	ft_export(char **cmd, t_env *env)
{
	char	*str;
	t_env	*ptr;
	int		i;

	i = 0;
	str = NULL;
	//mettre dans parsing
	if (cmd[1] == NULL || cmd[2])
	{
		ft_putendl_fd("export needs to have 1 argument", 2);
		return (1);
	}
	//tableau fini par \0 ou pas...
	ptr = ft_tab_check(env, cmd[1], '=');
	if (ptr == NULL)
	{
		//nommer les variables comme du monde 
		str = ft_strjoin(var_name, var_value);
		ft_lstadd_back(env, (t_list *)str);
		return 
	}
	str = ptr->content;
	if (str)
		ft_lstreplace(ptr, str);
	//rajouter conditions pour les erreurs
	return (0);
}

