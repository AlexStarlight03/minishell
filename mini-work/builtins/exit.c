/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:13:57 by adube             #+#    #+#             */
/*   Updated: 2023/10/25 15:49:22 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

bool	ft_exit(t_data data)
{
	//ad exit conditions/ error messages
	ft_lstclear((t_list **)data->env);
	exit(0);
}