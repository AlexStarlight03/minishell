/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:47:19 by adube             #+#    #+#             */
/*   Updated: 2024/01/18 14:17:28 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
bool	quote_check(char quote_type, char *arg)
{
	int		len;
	bool	first;
	bool	last;
	int		i;
	int		index;
	int		y;
	char	*new_arg;

	len = strlen(arg);
	first = false;
	last = false;
	i = 0;
	index = 0;
	y = 0;
	while(arg[i++])
	{
		if(arg[i] == quote_type)
		{
			first = true;
			break ;
		}
	}
	while(arg[len--])
	{
		if(arg[len] == quote_type)
		{
			last = true;
			break ;
		}
	}
	if (first == true && last == true)
	{
		new_arg = malloc(sizeof(char *));
		while (arg[index] != '\0')
		{
			if (index != i || index != len)
				new_arg[y] = arg[i];
			index++;
		}
		new_arg[y] = '\0';
		return (new_arg);
	}
	return (arg);
}

int	analyze(char *args)
{
	 bool	flag_singlequoteduo;
	 bool	flag_doublequoteduo;
	
	flag_singlequoteduo = quote_check(39, args);
	flag_doublequoteduo = quote_check(34, args);
	return (0);
}

void	ft_parse(char *input, t_env *env, t_mini *mini)
{
	int		cmd;
	char	**args;
	int		i;
	
	i = 0;
	args = ft_split(input, ' ');
	//while (args[i++])
	analyze(args[i]);
	cmd = is_a_builtin(args);
	if (cmd != 1)
		exec_builtin(mini, env, args, cmd);
	else
		return ;
}
