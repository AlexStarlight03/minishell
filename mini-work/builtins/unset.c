/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:14:27 by adube             #+#    #+#             */
/*   Updated: 2023/10/25 15:01:26 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

bool	ft_unset(t_data *data, char **cmd)
{
	char	*str;

	//ne pas oublier parsing
	str = ft_tab_check(data->env, cmd[1], '=');
	if (str)
	{
		ft_lstdelone(str);
		return (true);
	}
	return (false);
}
