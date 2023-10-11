/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:14:19 by adube             #+#    #+#             */
/*   Updated: 2023/10/11 11:14:18 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_env(t_msh *msh, char **args)
{
	int	i;
	t_env	*env;

	env = msh->env;
	i = 0;
	if(args[1])
	{
		ft_putendl_fd("Too many arguments", 2);
		return (1);
	}
	if (env)
	{
		while (env && env->next != NULL)
		{
			ft_putendl_fd(env->content, 1);
			env = env->next;
		}
		if (env)
			ft_putendl_fd(env->content, 1);
		return (0);
	}
	return (1);
}