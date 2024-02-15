/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:50:29 by mchampag          #+#    #+#             */
/*   Updated: 2024/02/14 23:57:28 by mchampag         ###   ########.fr       */
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

	len = (int)strlen(arg) - 1;
	i = 0;
	while(arg[i] != '\0' && arg[i] != quote_type)
		i++;
	while(arg[len] && len >= 0 && arg[len] != quote_type)
		len--;
	if (len != i)
		arg = arg_no_quote(arg, i, len);
	return (arg);
}
