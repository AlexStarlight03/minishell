/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:47:19 by adube             #+#    #+#             */
/*   Updated: 2024/02/14 23:57:38 by mchampag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*analyzer(char *args)
{
	//make sure it eliminates all quotes in the right order!!
	args = quote_checker(39, args);
	args = quote_checker(34, args);
	return (args);
}

void	parser(char *input, t_env *env, t_mini *mini)
{
	int		cmd;
	char	**args;
	int		i;
	int		j;
	
	j = 0;
	i = 0;
	args = ft_split(input, ' ');
	//args = ft_strtrim(input, " ");
	while (args[i])
	{
		args[i] = analyzer(args[i]);
		i++;
	}
	cmd = is_a_builtin(args);
	if (cmd != 1)
		exec_builtin(mini, env, args, cmd);
	else
	{
		cmd_path(args, mini, env);
		ft_pipex(mini);
	}
}
