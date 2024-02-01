/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:11:29 by mchampag          #+#    #+#             */
/*   Updated: 2024/02/01 13:07:23 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_table(char *str, char **tab)
{
	size_t	i;

	if (str)
		free(str);
	else if (tab)
	{
		i = -1;
		while (tab[++i])
			free(tab[i]);
		free(tab);
	}
}

int	check_error(int return_value, char *message)
{
	if (return_value == -1)
	{
		ft_putstr_fd(message, 2);
		exit(EXIT_FAILURE);
	}
	return (return_value);
}
