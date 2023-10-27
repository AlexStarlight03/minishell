/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:14:27 by adube             #+#    #+#             */
/*   Updated: 2023/10/27 10:18:05 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_lstone(t_mini *mini, t_env *env)
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
	char	*str;
	t_env	*temp;
	t_env	*env;

	
	env = mini->env;
	//ne pas oublier parsing
	str = ft_tab_check(mini->env, cmd[1], '=');
	if (str)
	{	
		temp = env->next->next;
		free_lstone(mini, env->next);
		env->next = temp;
		return (true);
	}
	return (false);
}
