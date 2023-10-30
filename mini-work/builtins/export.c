/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:13:52 by adube             #+#    #+#             */
/*   Updated: 2023/10/30 14:22:23 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// //mettre dans libft -- ajouter return bool
// bool	ft_str_in(char *big, char *little, char limit)
// {
// 	int	i;

// 	if (big == NULL || little == NULL)
// 		return (false);
// 	i = 0;
// 	while (big[i] != limit && little[i])
// 	{
// 		while (big[i] == little[i] && little[i])
// 			i++;
// 		if (big[i] == limit && little[i] == '\0')
// 			return (true);
// 	}
// 	return (false);
// }

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
	char	var_name[];
	char	env_name[];
	
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

t_env	*ft_lstlast(t_env *lst)
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
	last = ft_lstlast(env);
	last->next = new;
	last->next->next = NULL;
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
	check_env(env, cmd[1]);
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

