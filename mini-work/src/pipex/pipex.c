/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:11:40 by mchampag          #+#    #+#             */
/*   Updated: 2024/02/06 12:16:51 by adube            ###   ########.fr       */
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
		exit(ret);
	}
	else
		waitpid(pid, &ret, 0);
	ret = (ret == 32256 || ret == 32512) ? ret / 256 : !!ret;
	return (ret);
}

// void execute(t_mini *mini, int *fd)
// {
// 	char *envstr;
// 	char **env_tab;
// 	int error;
	
// 	envstr = env_str(mini->env);
// 	env_tab = ft_split(envstr, '\n');
// 	close(fd[0]);
// 	dup2(fd[1], 0);
// 	error = execve(mini->path, mini->command, env_tab); //put error returns
// 	if (error == -1)
// 		printf("%s\n", "execve error");
// 	//free_table(mini->path, mini->command);
// 	//free_table(envstr, 0);
// 	close(fd[1]);
// }

//  static void	child_process(int *fd, t_mini *mini)
// {
//  	check_error(dup2(fd[1], STDIN_FILENO), "Child fd[1] dup2() error");
//  	execute(mini, fd);
//  	check_error(-1, "execve error");
// }

// static void	parent_process(char *command2, int *fd, t_env *env)
// {
// 	close(fd[1]);
// 	check_error(dup2(fd[0], STDIN_FILENO), "Parent fd[0] dup2() error");
// 	cmd_path(command2, env);
// 	close(fd[0]);
// 	check_error(-1, "execve error");
// }

int	ft_pipex(t_mini *mini)
{
	// int		fd[2];
	// pid_t	pid;

	execute(mini->path, mini->command, mini->env);
	// check_error(pipe(fd), "Pipe error");
	// pid = fork();
	// check_error((int)pid, "Fork error");
	
	// child_process(fd, mini);
//	check_error(waitpid(pid, 0, 0), "waitpid error");
//	if (argv[2] != NULL)
//		parent_process(argv[2], fd, env);
	return (0);
}
