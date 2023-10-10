/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:14:19 by adube             #+#    #+#             */
/*   Updated: 2023/10/10 14:24:11 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_env(char *msh, char **args)
{
	int	i;	

	i = 0;
	if(args[1])
	{
		ft_putendl_fd("Too many arguments", 2);
		return (1);
	}
	else if (msh->env)
	{
		while (msh->env[i++])
			printf("%s", msh->env[i]);
	}
	return (0);
}