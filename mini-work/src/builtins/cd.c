/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:14:12 by adube             #+#    #+#             */
/*   Updated: 2024/02/01 15:03:39 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_path(t_mini *mini, char *var_name, int len)
{
	char	env_name[1024];
	char	*path;
	int		i;

	i = -1;
	path = NULL;
	while (mini->env && mini->env[++i])
	{
		get_var_name(env_name, mini->env[i]);
		if (ft_strcmp(var_name, env_name) == 0)
		{
			while (mini->env[i][len] != '\0')
				path[i++] = mini->env[i][len++];
			return (path);
		}
	}
	return (NULL);
}

void	change_oldpwd(t_mini *mini)
{
	char	cwd[1024];
	char	*oldpwd;

	getcwd(cwd, 1024);
	oldpwd = ft_strjoin("OLDPWD=", cwd);
	if (check_env(mini->env, oldpwd) != 0)
		env_add_back(mini->env, oldpwd);
	ft_memdel(oldpwd);
}

int	path_move(int dest, t_mini *mini)
{
	int		ret;
	char	*env_path;

	env_path = NULL;
	change_oldpwd(mini->env);
	ret = dest;
	env_path = get_path(mini, "HOME=", 5);
	if (!env_path)
	{
		//error mess and return error
		return (1);
	}
	ret = chdir(env_path);
	ft_memdel(env_path);
	return (ret);
}

int	cd(t_mini *mini, char **args)
{
	int	ret;

	if (!args[1])
	{
		ret = path_move(0, mini->env);
		return (ret);
	}
	else
	{
		change_oldpwd(mini);
		ret = chdir(args[1]);
		if (ret != 0)
			return (1);
			//error function;
	}
	return (ret);
}
