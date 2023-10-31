/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:53:13 by adube             #+#    #+#             */
/*   Updated: 2023/10/31 14:04:21 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	pipes_prep(t_mini *mini)
{
	pid_t	pid;
	int		pipe_fd[2];

	pipe(pipe_fd);
	pid = fork;
	if (pid == 0)
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], stdin);
	}
	else
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], stdout);
	}
}