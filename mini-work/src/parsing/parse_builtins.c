/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:31:00 by adube             #+#    #+#             */
/*   Updated: 2023/11/07 11:44:09 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <ctype.h>

char	*make_lower(char *arg)
{
	char *newstr;
	char new;
	int i;

	i = 0;
	newstr = malloc(sizeof(char *));
	while(arg[i] != '\0')
	{
		new = ft_tolower(arg[i]);
		newstr[i++] = new;
	}
	newstr[i] = '\0';
	return (newstr);
}

int	is_a_builtin(char **args)
{
	args[0] = make_lower(args[0]);
	if (ft_strcmp("cd", args[0]) == 0)
		return (CD);
	if (ft_strcmp("echo", args[0]) == 0)
		return (ECHO);
	if (ft_strcmp("env", args[0]) == 0)
		return (ENV);
	if (ft_strcmp("exit", args[0]) == 0)
		return (EXIT);
	if (ft_strcmp("export", args[0]) == 0)
		return (EXPORT);
	if (ft_strcmp("pwd", args[0]) == 0)
		return (PWD);
	if (ft_strcmp("unset", args[0]) == 0)
		return (UNSET);
	else
		return (1);
}
