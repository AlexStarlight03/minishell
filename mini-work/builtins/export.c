/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:13:52 by adube             #+#    #+#             */
/*   Updated: 2023/10/11 11:06:42 by adube            ###   ########.fr       */
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


int	ft_export(char **cmd, t_msh *msh)
{
	char	*str;
	int		i;

	i = 0;
	if (!cmd[1] || cmd[2])
	{
		ft_putendl_fd("export needs to have 1 argument", 2);
		return (1);
	}
	
	while(msh->env->next != NULL)
	{
		if (ft_str_in(msh->env->content, cmd[1]) == 0)
			break ;
		msh->env = msh->env->next;	
	}
	if (msh->env->next == NULL)
	{
		str = ft_strjoin(cmd[1], value)
		ft_lstadd_back((t_list)msh->env, (t_list)str);
		return (0);
	}
	while (msh->env->content[i] == cmd[1][i])
		i++;
	
}