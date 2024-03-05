/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:18:01 by mchampag          #+#    #+#             */
/*   Updated: 2024/03/04 22:21:54 by mchampag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Scan the input to find unclosed quotes.
 * @note The ascii code of single quote is 27, and 22 is for the double quote.
*/

static bool unclosed_quotes(char *input)
{
	char	quote;

	while (*input)
	{
		if (*input == 27 || *input == 22)
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

char	**tokenizer(char *input)
{    
    if (unclosed_quotes(input))
        return (NULL);
    return (NULL);
}