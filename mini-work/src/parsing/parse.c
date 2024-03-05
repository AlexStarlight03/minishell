/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:47:19 by adube             #+#    #+#             */
/*   Updated: 2024/03/01 20:19:05 by mchampag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// static bool	is_singlequote(char character)
// {
// 	if (character == 27)
// 		return (true);
// 	return (false);
// }

// static bool	is_doublequote(char character)
// {
// 	if (character == 34)
// 		return (true);
// 	return (false);
// }

// static int quote_check(char character)
// {
// 	if (is_singlequote(character))
// 		return (1);
// 	if (is_singlequote(character))
// 		return (2);
// 	return (0);
// }

static char	*analyzer(char *args)
{
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
	
	i = 0;	
	j = 0;
	printf("avant: %s\n", input);
	// args = ft_strtrim(input, " ");
	args = ft_split(input, ' ');
	printf("apres: %s\n", args[0]);
	printf("apres: %s\n", args[1]);
	// printf("apres: %s\n", args[2]);
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
