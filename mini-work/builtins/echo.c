/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:14:16 by adube             #+#    #+#             */
/*   Updated: 2023/10/31 15:14:59 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] != '\0')
		len++;
	return (len);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

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

int	main (int argc, char **argv)
{
	ft_echo(argv);
}
