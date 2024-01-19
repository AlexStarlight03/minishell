/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:32:11 by mchampag          #+#    #+#             */
/*   Updated: 2024/01/19 15:40:39 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static	char	*find_path(char *command, char *path)
{
	char	**paths;
	char	*test_path;
	size_t	i;

	if (!access(command, F_OK | X_OK))
		return (ft_strdup(command));
	paths = ft_split(path + 5, ':');
	i = -1;
	while (paths[++i])
	{
		test_path = ft_strjoin_free(paths[i], "/", 0);
		test_path = ft_strjoin_free(test_path, command, 1);
		if (!access(test_path, F_OK | X_OK))
			break ;
		free(test_path);
		test_path = 0;
	}
	ft_free_table(0, paths);
	return (test_path);
}

static char	*valid_env(char *command, char **envp)
{
	if (envp)
	{
		if (!envp[0])
			check_error(-1, "env is empty");
		if (command[0] == '/')
			return (command);
		while (!ft_strnstr(*envp, "PATH", 4))
		{
			envp++;
			if (!*envp)
				check_error(-1, "No PATH");
		}
		return (*envp);
	}
	else
		check_error(-1, "No env");
	return (0);
}

void	execute(char *command, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(command, ' ');
	path = find_path(cmd[0], valid_env(command, envp));
	if (cmd && path)
		execve(path, cmd, envp);
	ft_free_table(path, cmd);
}
