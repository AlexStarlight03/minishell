/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:51:39 by adube             #+#    #+#             */
/*   Updated: 2024/01/29 11:56:10 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//needs to split what env_path returns in a char **paths

char	**env_paths(t_env *env)
{
	char	**path_tab;
	char	*path;
	path = env->content;
	while (ft_strncmp("PATH", path, 4))
	{
		env = env->next;
		path = env->content;	
	}
	path_tab = ft_split(path, ':');
	return (path_tab);
}

bool	find_cmd(char *cmd, t_env *env)
{
	char	*temp;
	char	*command;
	char	**paths;

	paths = env_paths(env);
	while (*paths)
	{
		temp = ft_strjoin(*paths, "/");
		command = ft_strjoin(temp, cmd);
		free(temp);
		if (access(command, 0) == 0)
			return (true);
		free(command);
		paths++;
	}
	return (true);
}
