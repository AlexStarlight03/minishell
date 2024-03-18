/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:47:51 by mchampag          #+#    #+#             */
/*   Updated: 2024/03/07 23:25:41 by mchampag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


/**
 * @brief Create token.
*/

static int	token_creator(char *input, t_list **tokens, int len_token)
{
	char	*tmp;
	t_list	*node;

	tmp = ft_substr(input, 0, len_token);
	if (tmp == NULL)
		return (EXIT_FAILURE);
	node = ft_lstnew(tmp);
	// printf("tmp: %d\n", tmp[0]);
	printf("tmp: %s\n", tmp);
	if (node == NULL)
		return (EXIT_FAILURE);
	ft_lstadd_back(tokens, node);
	return (EXIT_SUCCESS);
}

/**
 * @brief Create text token.
*/

static void	create_text_token(char *input, t_list **tokens, char *start)
{
	int	len_token;

	len_token = ft_strlen(start) - ft_strlen(input);
	if (len_token > 0)
		token_creator(start, tokens, len_token);
}

/**
 * @brief Check if there is a text token, then to the separator token.
 * @note The ascii code for space is 32, 9 is for horizontal tabulation,
 * 124 for pipe, 60 for < and 62 for >.
 */

static bool	create_separator_token(char *input, t_list **tokens, char *start)
{
	// printf("input: %c\n", *input);
	if (*input == 32 || *input == 9 || *input == 124 || *input == 60
		|| *input == 62)
	{
		create_text_token(input, tokens, start);
		token_creator(input, tokens, 1);
		return (1);
	}
	return (0);
}

/**
 * @brief Find everything between two quotes (single or double)
 * to make a "word", including quotes.
 * @note The ascii code of single quote is 39, and 34 is for double quote.
*/

static bool	step_through_quotes(char **input, char quote)
{
	if (**input == 39 || **input == 34)
	{
		(*input)++;
		while (*input)
		{
			// printf("input: %c\n", **input);
			if (**input == quote)
				return (1);
			(*input)++;
		}
	}
	return (0);
}

/**
 * @brief Separate input into tokens.
*/

void	tokenizer(char *input, t_list **tokens)
{
	char	*start;

	start = input;
	while (*input)
	{
		if (step_through_quotes(&input, *input))
			input++;
		else if (create_separator_token(input, tokens, start))
		{
			input++;
			start = input;
		}	
		else
			input++;
	}
	create_text_token(input, tokens, start);
}
