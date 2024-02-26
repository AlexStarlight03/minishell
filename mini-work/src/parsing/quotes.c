/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:50:29 by mchampag          #+#    #+#             */
/*   Updated: 2024/02/22 21:40:46 by mchampag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*arg_no_quote(char *arg, int quote1, int quote2)
{
		int		i;
		int		index;
		char	*new_arg;
		
		i = 0;
		index = 0;
		new_arg = malloc(sizeof(char *) * strlen(arg) - 2);
		while (arg[i] != '\0')
		{
			if (i != quote1 && i != quote2)
				new_arg[index++] = arg[i];
			i++;
		}
		new_arg[index] = '\0';
		return (new_arg);
}

char	*quote_checker(char quote_type, char *arg)
{
	int		len;
	int		i;

	len = (int)ft_strlen(arg);
	printf("%d\n", len);
	printf("%s\n", arg);
	i = 0;
	while(arg[i] != '\0' && arg[i] != quote_type)
		i++;
	while(arg[len] && len >= 0 && arg[len] != quote_type)
		len--;
	if (len != i)
		arg = arg_no_quote(arg, i, len);
	return (arg);
}


// ➜  ~ ''
// zsh: permission denied:
// ➜  ~ ' '
// zsh: command not found:
// ➜  ~ " "
// zsh: command not found:
// ➜  ~ ""
// zsh: permission denied:

