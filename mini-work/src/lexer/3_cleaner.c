/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_cleaner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 20:41:01 by mchampag          #+#    #+#             */
/*   Updated: 2024/03/20 21:44:38 by mchampag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	exit_cleaner(t_mini *mini, t_list **tokens)
{
	mini->lastexitstatus = SYNTAX;
	printf("syntax error\n");
	ft_lstclear(tokens, &ft_del);
	return (EXIT_FAILURE);
}

static bool	handle_redirection(t_mini *mini, t_list **tokens, t_list **ptr)
{
	char	opposite[2];

	opposite[0] = '\0';
	if (ft_strcmp((*ptr)->content, ">"))
		ft_strcpy(opposite, "<");
	else if (ft_strcmp((*ptr)->content, "<"))
		ft_strcpy(opposite, ">");
	if (opposite[0] == '<' || opposite[0] == '>')
	{
		if ((*ptr)->next == NULL || ft_strcmp((*ptr)->next->content, opposite))
			return (exit_cleaner(mini, tokens));
		if (ft_strcmp((*ptr)->next->content, (*ptr)->content))
		{
			if (ft_strappend((char **)&(*ptr)->content, (*ptr)->content))
				return (EXIT_FAILURE);
			ft_lstremovenode(tokens, (*ptr)->next, &ft_del);
		}
		if (ft_strcmp((*ptr)->content, "<<") || ft_strcmp((*ptr)->content, ">>"))
		{
			if ((*ptr)->next == NULL || ft_strcmp((*ptr)->next->content, "<")
				|| ft_strcmp((*ptr)->next->content, ">"))
				return (exit_cleaner(mini, tokens));
		}
		*ptr = (*ptr)->next;
	}
	return (EXIT_SUCCESS);
}

static bool	handle_pipe(t_list *ptr)
{
	if (ft_strcmp(ptr->content, "|"))
	{
		if (ptr->next == NULL || ft_strcmp(ptr->next->content, "|"))
			return (EXIT_FAILURE);
		else
			((char *)ptr->content)[0] = PIPE;
	}
	return (EXIT_SUCCESS);
}

static bool	handle_space(t_list **tokens, t_list *ptr)
{
	if (ft_strcmp(ptr->content, " ")) // strcmp modifie
	{
		printf("ptr space1: %s\n", (char*)ptr->content);
		ft_lstremovenode(tokens, ptr, &ft_del);
		printf("ptr space2: %s\n", (char*)ptr->content);
		return (true);
	}
	return (false);
}

// refaire conditions pour qu'elles fit
bool	token_cleaner(t_mini *mini, t_list **tokens)
{
	t_list	*ptr;

	ptr = *tokens;
	while (ptr)
	{
		// printf("ptr : %s\n", (char *)ptr->content);
		if (handle_space(tokens, ptr))
			ptr = *tokens;
		else if (handle_pipe(ptr))
			return (exit_cleaner(mini, tokens));
		else if (handle_redirection(mini, tokens, &ptr))
			return (EXIT_FAILURE);
		else
			ptr = ptr->next;
	}
	return (EXIT_SUCCESS);
}
