/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:11:40 by mchampag          #+#    #+#             */
/*   Updated: 2024/02/01 16:27:35 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void execute(t_mini *mini)
{
	execve(mini->path, mini->command, mini->env); //put error returns
	free_table(mini->path, mini->command);
}

static void	child_process(int *fd, t_mini *mini)
{
	close(fd[0]);
	check_error(dup2(fd[1], STDOUT_FILENO), "Child fd[1] dup2() error");
	execute(mini);
	close(fd[1]);
	//check_error(-1, "execve error");
}

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
	int		fd[2];
	pid_t	pid;


	check_error(pipe(fd), "Pipe error");
	pid = fork();
	check_error((int)pid, "Fork error");
	if (pid == 0)
		child_process(fd, mini);
	check_error(waitpid(pid, 0, 0), "waitpid error");
//	if (argv[2] != NULL)
//		parent_process(argv[2], fd, env);
	return (0);
}
