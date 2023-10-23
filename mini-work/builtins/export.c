/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:13:52 by adube             #+#    #+#             */
/*   Updated: 2023/10/23 11:43:26 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_str_in(char *big, char *little)
{
	int	i;
	int	y;

	if (!big)
		return (0);
	if (*little == '\0')
		return (1);
	while (big[i] != '=' && ft_strlen(little))
	{
		i = 0;
		while (little[i] == big[i] && little[i] != '\0')
			i++;
		if (little[i] == '\0' && big[i] == '=')
			return (0);
	}
	return (1);
}


int	ft_export(char **cmd, t_data *data)
{
	char	*str;
	int		i;

	i = 0;
	if (!cmd[1] || cmd[2])
	{
		ft_putendl_fd("export needs to have 1 argument", 2);
		return (1);
	}
	
	while(data->env[i] != NULL)
	{
		if (ft_str_in(data->env[i++], cmd[1]) == 0)
			break ;	
	}
	if (data->env == NULL)
	{
		str = ft_strjoin(cmd[1], value);
		ft_lstadd_back((t_list)msh->env, (t_list)str);
		return (0);
	}
	while (data->env[i] == cmd[1][i])
		i++;
	
}