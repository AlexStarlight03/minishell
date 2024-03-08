/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:18:01 by mchampag          #+#    #+#             */
/*   Updated: 2024/03/05 23:01:46 by mchampag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Scan the input to find unclosed quotes.
 * @note The ascii code of single quote is 39, and 34 is for the double quote.
*/

static bool unclosed_quotes(char *input)
{
	char	quote;

	while (*input)
	{	
		if (*input == 39 || *input == 34)
		{
			quote = *input;
			input++;
			while (*input && *input != quote)
				input++;
			if (!*input)
			{
				printf("Error: unclosed quotes\n");
				return (true);
			}
		}
		input++;
	}
	return (false);
}

char	**lexer(t_mini *mini, char *input)
{    
    t_list *tokens;
    
	(void)*mini;
    if (unclosed_quotes(input))
        return (NULL);
    tokens = NULL;
    tokenizer(input, &tokens);
    return (NULL);
}