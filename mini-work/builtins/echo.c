/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:14:16 by adube             #+#    #+#             */
/*   Updated: 2023/10/18 14:28:39 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	args_count(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}
int	ft_echo(char **args)
{
	int		i;
	bool	newline;

	newline = false;
	i = 1;
	if (args_count(args) > 1)
	{
		if (args[1][0] == '-' && args[1][1] == 'n' && args[1][2] == '\0')
		{
			newline = true;
			i++;
		}
		while (args[i])
		{
			ft_putstr_fd(args[i], 1);
			if (args[i + 1])
				write(1, " ", 1);
		}
	}
	if (newline == false)
		write(1, "\n", 1);
	return (0);
}