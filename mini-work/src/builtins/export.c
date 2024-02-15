/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:13:52 by adube             #+#    #+#             */
/*   Updated: 2024/02/14 22:40:59 by mchampag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_export(char **cmd, t_env *env)
{
	int		i;
	t_env 	*temp;
	int		flag;
	
	i = 0;
	while (cmd[++i])
	{
		flag = 0;
		temp = env;
		if (check_env(temp, cmd[i]) == 0)
 			flag = 1;
 		else if (flag != 1)
 			env_add_back(temp, cmd[i]);
		env = temp;
	}
	return (0);
}