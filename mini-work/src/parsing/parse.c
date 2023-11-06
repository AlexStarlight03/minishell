/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:47:19 by adube             #+#    #+#             */
/*   Updated: 2023/11/06 12:34:18 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_parse(char **args, t_env *env, t_mini *mini)
{
	int cmd;
	
	if ((cmd = is_a_builtin(args)) != 1)
	{
		if (cmd == CD)
			cd(env, args);
		if (cmd == ECHO)
			ft_echo(args);
		if (cmd == ENV)
			ft_env(env);
		if (cmd == EXIT)
			ft_exit(mini, env);
		if (cmd == EXPORT)
			ft_export(args, env);
		if (cmd == UNSET)
			ft_unset(mini, args);
		if (cmd == PWD)
			ft_pwd();
	}
	else
		return ;
}
