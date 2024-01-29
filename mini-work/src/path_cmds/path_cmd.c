/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:51:39 by adube             #+#    #+#             */
/*   Updated: 2024/01/29 14:48:50 by adube            ###   ########.fr       */
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
		//if (!path)
			//  error function no path	
	}
	path_tab = ft_split(path, ':');
	return (path_tab);
}

char	*find_cmd(char *cmd, t_env *env)
{
	char	*temp;
	char	*command;
	char	**paths;

	paths = env_paths(env);
	if (cmd[0] == '/')
		return(cmd);
	while (*paths)
	{
		temp = ft_strjoin(*paths, "/");
		command = ft_strjoin(temp, cmd);
		free(temp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}
