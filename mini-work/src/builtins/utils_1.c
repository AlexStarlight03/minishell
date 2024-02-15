/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:25:34 by mchampag          #+#    #+#             */
/*   Updated: 2024/02/14 22:43:37 by mchampag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_var_name(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != '=' && ft_strlen(src) < BUFFER_SIZE)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	free_lst_node(t_mini *mini, t_env *env)
{
	if (mini->env == env && env->next != NULL)
	{
		ft_memdel(mini->env->content);
		mini->env->content = NULL;
		mini->env->next = NULL;
		return ;
	}
	ft_memdel(env->content);
	ft_memdel((char *)env);
}

t_env	*lstsecondlast(t_env *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}
