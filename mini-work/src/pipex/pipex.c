/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:11:40 by mchampag          #+#    #+#             */
/*   Updated: 2024/01/29 14:33:44 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	child_process(char *infile, char *command1, int *fd, t_env *env)
{
	int		new_fd_in;

	close(fd[0]);
	new_fd_in = check_error(open(infile, O_RDONLY, 0644), "Open error");
	check_error(dup2(fd[1], STDOUT_FILENO), "Child fd[1] dup2() error");
	check_error(dup2(new_fd_in, STDIN_FILENO), "Child new_fd dup2() error");
	cmd_path(command1, env);
	close(fd[1]);
	close(new_fd_in);
	check_error(-1, "execve error");
}

static void	parent_process(char *outfile, char *command2, int *fd, t_env *env)
{
	int		new_fd_out;

	close(fd[1]);
	new_fd_out = check_error(open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644),
			"Open error");
	check_error(dup2(fd[0], STDIN_FILENO), "Parent fd[0] dup2() error");
	check_error(dup2(new_fd_out, STDOUT_FILENO), "Parent new_fd dup2() error");
	cmd_path(command2, env);
	close(fd[0]);
	close(new_fd_out);
	check_error(-1, "execve error");
}

int	ft_pipex(char **argv, t_env *env)
{
	int		fd[2];
	pid_t	pid;

//	if (argc == 5)
//	{
		check_error(pipe(fd), "Pipe error");
		pid = fork();
		check_error((int)pid, "Fork error");
		if (pid == 0)
			child_process(argv[0], argv[1], fd, env);
		check_error(waitpid(pid, 0, 0), "waitpid error");
		parent_process(argv[3], argv[2], fd, env);
//	}
	return (0);
}
