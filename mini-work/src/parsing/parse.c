/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:47:19 by adube             #+#    #+#             */
/*   Updated: 2024/02/14 20:24:27 by mchampag         ###   ########.fr       */
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
	//make sure it eliminates all quotes in the right order!!
	args = quote_check(39, args);
	args = quote_check(34, args);
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
		args[i] = analyze(args[i]);
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
