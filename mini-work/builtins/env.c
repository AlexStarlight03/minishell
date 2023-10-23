/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:14:19 by adube             #+#    #+#             */
/*   Updated: 2023/10/23 11:26:19 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_env(t_data *data)
{
	int	i;

	i = 0;
	//if(args[1])
	//{
	//	ft_putendl_fd("Too many arguments", 2);
	//	return (1);
	//}

	while (data->env[i])
	{
			ft_putendl_fd(data->env[i++], 1);
	}
	return (0);
}
