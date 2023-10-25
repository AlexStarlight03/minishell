/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:13:52 by adube             #+#    #+#             */
/*   Updated: 2023/10/25 15:20:54 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

//mettre dans libft -- ajouter return bool
bool	ft_str_in(char *big, char *little, char limit)
{
	int	i;

	if (big == NULL || little == NULL)
		return (false);
	i = 0;
	while (big[i] != limit && little[i])
	{
		while (big[i] == little[i] && little[i])
			i++;
		if (big[i] == limit && little[i] == '\0')
			return (true);
	}
	return (false);
}

char *ft_tab_check(char **tab, char *str, char limit)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (ft_str_in(tab[i], str, limit))
			return (tab[i]);
	}
	return (NULL);
}

bool	ft_lstreplace(t_list *list, void *str)
{
	if (list == NULL)
		return (false);
	list->content = str;
	return (0);
}

int	ft_export(char **cmd, t_data *data)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	//mettre dans parsing
	if (cmd[1] == NULL || cmd[2])
	{
		ft_putendl_fd("export needs to have 1 argument", 2);
		return (1);
	}
	//tableau fini par \0 ou pas...
	str = ft_tab_check(data->env, cmd[1], '=');
	if (str)
	{
		ft_lstdelone((t_list *)str);
		ft_lstreplace((t_list *)data->env, &str);
	}
	else (str == NULL)
	{
		//nommer les variables comme du monde 
		str = ft_strjoin(var_name, var_value);
		ft_lstadd_back(data->env, str);
	}
	while (data->env[i] == cmd[1][i])
		i++;
	
}

