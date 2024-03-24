/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_command_creator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:01:27 by mchampag          #+#    #+#             */
/*   Updated: 2024/03/23 20:49:41 by mchampag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	**redirection_tokenizer(char **command)
{
	int	i;

	i = 0;
	while (command[i])
	{
		printf("red1: %s\n", command[i]);
		if (command[i][0] == '<')
		{
			command[i][0] = LESS;
			if (command[i][1] == '<')
				command[i][1] = LESS;
		}	
		else if (command[i][0] == '>')
		{
			command[i][0] = GREATER;
			if (command[i][1] == '>')
				command[i][1] = GREATER;
		}
		printf("red2: %s\n", command[i]);
		i++;
	}
	return (command);
}

char	**command_creator(t_list **tokens)
{
	char	**command;
	t_list	*tmp;
	int		i;

	command = malloc((ft_lstsize(*tokens) + 1) * sizeof(char *));
	if (!command)
		return (NULL);
	tmp = *tokens;
	i = 0;
	while (tmp)
	{
		command[i] = ft_strdup(tmp->content);
		if (!command[i++])
			return (NULL);
		tmp = tmp->next;
	}
	command[i] = NULL;
	ft_lstclear(tokens, &ft_del);
	return (redirection_tokenizer(command));
}
