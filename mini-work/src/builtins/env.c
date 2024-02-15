/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:14:19 by adube             #+#    #+#             */
/*   Updated: 2024/02/14 22:47:00 by mchampag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_env(t_env *env)
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
