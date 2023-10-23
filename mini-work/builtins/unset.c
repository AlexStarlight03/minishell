/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:14:27 by adube             #+#    #+#             */
/*   Updated: 2023/10/23 11:49:56 by adube            ###   ########.fr       */
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

//void	ft_free_node(t_msh *msh, t_env *env)
//{
//	if (msh->env == env && env->next == NULL)
//	{
//		free(msh->env->content);
//		msh->env->content = NULL;
//		msh->env->next = NULL;
//		return ;
//	}
//	free(env->content);
//	env->content = NULL;
//	free(env);
//	env = NULL;
//	return ;
//}

int		ft_unset(t_data *data, char **args)
{
	char	*temp;
	int		i;

	i = 0;
	if (!args[1])
		return (0);
	while (data->env[i] && data->env[i + 1] != NULL)
	{
		if (ft_strncmp(args[1], data->env[i], env_var_cut(data->env[i])) == 0)
		{
			temp = data->env[i + 1];
			free(data->env[i]);
			data->env[i] = temp;
			return (0);
		}
		i++;
}