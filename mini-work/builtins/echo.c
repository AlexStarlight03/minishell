/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:14:16 by adube             #+#    #+#             */
/*   Updated: 2023/10/11 11:04:08 by adube            ###   ########.fr       */
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
	int	i;
	int	n;

	n = 0;
	i = 1;
	if (args_count > 1)
	{
		if (ft_strncmp(args[1], "-n", 2) == 0)
		{
			n = 1;
			i++;
		}
		while (args[i])
		{
			ft_putstr_fd(args[i], 1);
			if (args[i + 1])
				write(1, " ", 1);
		}
	}
	if (n == 0)
		write(1, "\n", 1);
	return (0);
}