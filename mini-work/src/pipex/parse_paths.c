/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:32:11 by mchampag          #+#    #+#             */
/*   Updated: 2024/02/06 12:16:40 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
		test_path = ft_strjoin(paths[i], "/");
		test_path = ft_strjoin(test_path, command);
		if (!access(test_path, F_OK | X_OK))
			break ;
		free(test_path);
		test_path = 0;
	}
	free_table(0, paths);
	return (test_path);
}

static char	*valid_env(char *command, t_env *env)
{
	if (env)
	{
		if (!env)
			check_error(-1, "env is empty");
		if (command[0] == '/')
			return (command);
		while (!ft_strnstr(env->content, "PATH", 4))
		{
			env = env->next;
			if (!env->content)
				check_error(-1, "No PATH");
		}
		return (env->content);
	}
	else
		check_error(-1, "No env");
	return (0);
}

int	cmd_path(char **command, t_mini *mini, t_env *env)
{
	int i;
	i = 0;
	mini->command = command;
	mini->path = find_path(mini->command[0], valid_env(command[0], env));
	printf("%s", mini->path);
	if (mini->command && mini->path)
		return (0); //put error returns
	else
	{
		// printf("%s", "error with path and command");
		return (-1);
	}
}
