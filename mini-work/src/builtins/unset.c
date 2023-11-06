/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:14:27 by adube             #+#    #+#             */
/*   Updated: 2023/11/06 12:43:10 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

size_t	name_len(char *env)
{
	size_t	i;

	i = 0;
	while(env[i] && env[i] != '=')
		i++;
	return(i);
}

void	free_lst_node(t_mini *mini, t_env *env)
{
	if (mini->env == env && env->next != NULL)
	{
		ft_memdel(mini->env->content);
		mini->env->content = NULL;
		mini->env->next = NULL;
		return ;
	}
	ft_memdel(env->content);
	ft_memdel(env);
}

bool	ft_unset(t_mini *mini, char **cmd)
{
	t_env	*temp;
	t_env	*env;

	env = mini->env;
	//ne pas oublier parsing
	while (env && env->next)
	{
		if (ft_strncmp(cmd[1], env->next->content, name_len(env->next->content)) == 0)
		{	
			temp = env->next->next;
			free_lst_node(mini, env->next);
			env->next = temp;
		}
		env = env->next;
	}
	return (true);
}
