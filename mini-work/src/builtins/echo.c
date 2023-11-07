/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:14:16 by adube             #+#    #+#             */
/*   Updated: 2023/11/07 13:58:23 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//gerer dans le parsing les quote et double quotes!!!

static int	args_count(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

void	ft_echo(char **args)
{
	int		i;
	bool	newline;

	newline = true;
	i = 1;
	if (args_count(args) > 1)
	{
		//deplacer dans le parsing!
		if (args[1][0] == '-' && args[1][1] == 'n' && args[1][2] == '\0')
		{
			newline = false;
			i++;
		}
		while (args[i])
		{
			ft_putstr_fd(args[i], 1);
			if (args[i + 1])
				write(1, " ", 1);
			i++;
		}
	}
	if (newline == true)
		write(1, "\n", 1);
}
