/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:47:19 by adube             #+#    #+#             */
/*   Updated: 2024/01/18 16:42:50 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
char	*quote_check(char quote_type, char *arg)
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
	//printf("%c", quote_type);
	while(arg[i++] != '\0')
	{
		if(arg[i] == quote_type)
		{
			first = true;
			break ;
		}
	}
	while(arg[len--] && len >= 0)
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
			if (arg[index] != 39 && arg[index] != 34)
				new_arg[y++] = arg[index];
			index++;
		}
		new_arg[y] = '\0';
	//	printf("%s", new_arg);
		return (new_arg);
	}
	return (arg);
}

char	*analyze(char *args)
{
	args = quote_check(39, args);
	args = quote_check(34, args);
	return (args);
}

void	ft_parse(char *input, t_env *env, t_mini *mini)
{
	int		cmd;
	char	**args;
	int		i;
	int		j;
	
	j = 0;
	i = 0;
	args = ft_split(input, ' ');
	while (args[i])
	{
		args[i] = analyze(args[i]);
		i++;
	}
	cmd = is_a_builtin(args);
	if (cmd != 1)
		exec_builtin(mini, env, args, cmd);
	else
		return ;
}
