/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:47:19 by adube             #+#    #+#             */
/*   Updated: 2024/02/22 22:58:35 by mchampag         ###   ########.fr       */
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
	

	// int		quote;
	
	i = 0;
	// quote = 0;
	// printf("%s", input);
	// if (input)
	// {
	// 	while (*input == 32 && *input != '\n')
	// 		input++;
	// 	printf("%s", input);
	// }
	
	// scanf(" ");



		
	j = 0;
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
