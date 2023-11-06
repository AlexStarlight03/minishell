/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:31:00 by adube             #+#    #+#             */
/*   Updated: 2023/11/06 13:52:51 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <ctype.h>

int	is_a_builtin(char **args)
{
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
