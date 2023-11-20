/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:47:19 by adube             #+#    #+#             */
/*   Updated: 2023/11/20 12:41:33 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
int	quote_check(char quote_type, char *arg)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	while(arg[i++])
	{
		if(arg[i] == quote_type)
			nb += 1;
	
	}
	return (nb);
}

int	analyze(char **args)
{
	 int	flag_singlequote;
	 int	flag_doublequote;
	 int	i;

	i = 0;
	flag_singlequote = quote_check( 39, args[i]);
	flag_doublequote = quote_check( 34, args[i]);
}

void	ft_parse(char *input, t_env *env, t_mini *mini)
{
	int		cmd;
	char	**args;

	args = ft_split(input, ' ');
	analyze(args);
	cmd = is_a_builtin(args);
	if (cmd != 1)
		exec_builtin(mini, env, args, cmd);
	else
		return ;
}
