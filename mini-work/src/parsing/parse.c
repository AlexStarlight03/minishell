/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:47:19 by adube             #+#    #+#             */
/*   Updated: 2024/02/01 16:27:35 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*arg_no_quote(char *arg, int quote1, int quote2)
{
		int		i;
		int		index;
		char	*new_arg;
		
		i = 0;
		index = 0;
		new_arg = malloc(sizeof(char *) * strlen(arg) - 2);
		while (arg[i] != '\0')
		{
			if (i != quote1 && i != quote2)
				new_arg[index++] = arg[i];
			i++;
		}
		new_arg[index] = '\0';
		return (new_arg);
}

char	*quote_check(char quote_type, char *arg)
{
	int		len;
	int		i;

	len = (int)strlen(arg) - 1;
	i = 0;
	while(arg[i] != '\0' && arg[i] != quote_type)
		i++;
	while(arg[len] && len >= 0 && arg[len] != quote_type)
		len--;
	if (len != i)
		arg = arg_no_quote(arg, i, len);
	return (arg);
}

char	*analyze(char *args)
{
	args = quote_check('\"', args);
	args = quote_check('\'', args);
	return (args);
}

void	parse(char *input, char **env, t_mini *mini)
{
	int		cmd;
	char	*command;
	char	*path;
	char	**args;
	int		index;

	index = 0;
	args = ft_split(input, ' ');
	while (args[index])
	{
		args[index] = analyze(args[index]);
		index++;
	}
	cmd = is_a_builtin(args);
	if (cmd != 1)
		exec_builtin(mini, env, args, cmd);
	cmd_path(args, env); // main
	ft_pipex(mini); // main
	//printf("%s\n", command);
	//if (command != NULL)
	//	execve(command, args, 0); //passer notre env comme du monde
//	return ;
}
