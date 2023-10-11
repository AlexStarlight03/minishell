/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:14:27 by adube             #+#    #+#             */
/*   Updated: 2023/10/11 12:10:14 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		*env_var_cut(char *env)
{
	int	i;

	i = 0;
	while(env[i] && env[i] != '=')
		i++;
	return (i);
}

void	ft_free_node(t_msh *msh, t_env *env)
{
	if (msh->env == env && env->next == NULL)
	{
		free(msh->env->content);
		msh->env->content = NULL;
		msh->env->next = NULL;
		return ;
	}
	free(env->content);
	env->content = NULL;
	free(env);
	env = NULL;
	return ;
}

int		ft_unset(t_msh *msh, char **args)
{
	t_env *env;
	t_env *temp;

	env = msh->env;
	if (!args[1])
		return (0);
	while (env && env->next != NULL)
	{
		if (ft_strncmp(args[1], env->content, env_var_cut(env->content)) == 0)
		{
			temp = env->next;
			ft_free_node(msh, env);
			env = temp;
			return (0);
		}
		env = env->next;
			
	
}