/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:11:40 by mchampag          #+#    #+#             */
/*   Updated: 2024/02/27 13:03:44 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int			execute(char *path, char **args, t_env *env)
{
	char	**env_tab;
	char	*arrayenv;
	int		pid;
	int		ret;

	ret = 0;
	pid = fork();
	if (pid == 0)	
	{
		arrayenv = env_str(env);
		env_tab = ft_split(arrayenv, '\n');
		ft_memdel(arrayenv);
		if (ft_strchr(path, '/') != NULL)
			execve(path, args, env_tab);
		free_table(NULL, env_tab);
		exit(ret);
	}
	else
		waitpid(pid, &ret, 0);
	ret = (ret == 32256 || ret == 32512) ? ret / 256 : !!ret;
	return (ret);
}

int	ft_pipex(t_mini *mini)
{
	execute(mini->path, mini->command, mini->env);
	free_table(mini->path, mini->command);

	return (0);
}
