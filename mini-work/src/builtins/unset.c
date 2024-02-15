/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:14:27 by adube             #+#    #+#             */
/*   Updated: 2024/02/14 22:28:21 by mchampag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static size_t	name_len(char *env)
{
	size_t	i;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	return (i);
}

bool	ft_unset(t_mini *mini, char **cmd)
{
	t_env	*temp;
	t_env	*env;
	int		i;
	
	i = 0;
	while (cmd[++i])
	{
		env = mini->env;
		while (env && env->next)
		{
			if (ft_strncmp(cmd[i], env->next->content, \
							name_len(env->next->content)) == 0)
			{
				temp = env->next->next;
				free_lst_node(mini, env->next);
				env->next = temp;
			}
			env = env->next;
		}

	}
	return (true);
}
