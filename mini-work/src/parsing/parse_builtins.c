/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:31:00 by adube             #+#    #+#             */
/*   Updated: 2023/11/06 11:26:20 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_a_builtin(char **args)
{
	int	i;
	
	i = 0;
	while (args[0][i++] != '\0')
		ft_tolower((int)&args[0][i]);
	if (ft_strncmp("cd", args[0], 2) == 0)
		return (CD);
	if (ft_strncmp("echo", args[0], 4) == 0)
		return (ECHO);
	if (ft_strncmp("env", args[0], 3) == 0)
		return (ENV);
	if (ft_strncmp("exit", args[0], 4) == 0)
		return (EXIT);
	if (ft_strncmp("export", args[0], 6) == 0)
		return (EXPORT);
	if (ft_strncmp("pwd", args[0], 3) == 0)
		return (PWD);
	if (ft_strncmp("unset", args[0], 5) == 0)
		return (UNSET);
	else
		return (1);
}
