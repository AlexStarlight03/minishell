/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:13:52 by adube             #+#    #+#             */
/*   Updated: 2023/10/10 15:07:49 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

bool	ft_str_in(char *big, char *little)
{
	int	i;
	int	y;

	if (!big)
		return (0);
	if (*little == '\0')
		return (false);
	while (big[i] != '=' && ft_strlen(little))
	{
		i = 0;
		while (little[i] == big[i] && little[i] != '\0')
			i++;
		if (little[i] == '\0' && big[i] == '=')
			return (true);
	}
	return (false);
}


bool	ft_export(char **cmd, char *msh)
{
	char	*str;
	int		i;

	i = 0;
	if (!cmd[1] || cmd[2])
	{
		ft_putendl_fd("export needs to have 1 argument", 2);
		return (false);
	}
	
	while(msh->env->next != NULL)
	{
		if (ft_str_in(msh->env->content, cmd[1]) == true)
			break ;
		msh->env = msh->env->next;	
	}
	if (msh->env->next == NULL)
	{
		str = ft_strjoin(cmd[1], value)
		ft_lstadd_back(msh->env, str);
		return (true);
	}
	while (msh->env->content[i] == cmd[1][i])
		i++;
	
}