/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:14:24 by adube             #+#    #+#             */
/*   Updated: 2023/10/31 14:43:43 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_pwd(void)
{
	char *pwd;
	// if env && if $PWD
	pwd = getcwd(pwd, sizeof(char *));
	if (pwd)
	{
		printf("%s\n", pwd);
		return (0);
	}
	return (1);
}
