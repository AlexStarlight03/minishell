/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:14:12 by adube             #+#    #+#             */
/*   Updated: 2023/10/31 15:14:59 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_path(t_env *env, char *var_name, int len)
{
	char	env_name[1024];
	char 	*path;
	int		i;
	
	i = 0;
	while(env && env->next)
	{
		get_var_name(env_name, env->content);
		if(ft_strcmp(var_name, env_name) == 0)
		{
			while (env->content[len] != '\0')
				path[i++] = env->content[len++];
			return (path);
		}
		env = env->next;
	}
	return (1);
}

void	change_oldpwd(t_env *env)
{
	char	cwd[1024];
	char	*oldpwd;

	getcwd(cwd, 1024);
	oldpwd = ft_strjoin("OLDPWD=", cwd);
	if (check_env(env, oldpwd) != 0)
		env_add_back(env, oldpwd);
	ft_memdel(oldpwd);
}

int	path_move(int dest, t_env *env)
{
	int		ret;
	char	*env_path;

	env_path = NULL;
	change_oldpwd(env);
	env_path = get_path(env, "HOME=", 5);
	if (!env_path)
	{
		//error mess and return error
	}
	ret = chdir(env_path);
	ft_memdel(env_path);
	return (ret);
}

int	cd(t_env *env, char **args)
{
	int	ret;
	
	if(!args[1])
	{
		ret = path_move(0, env);
		return (ret);
	}
	else
	{
		change_oldpwd(env);
		ret = chdir(args[1]);
		if ( ret != 0)
			return (1);
			//error function;
	}
	return (ret);	
}
