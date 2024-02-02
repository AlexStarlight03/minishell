/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:14:24 by adube             #+#    #+#             */
/*   Updated: 2024/02/02 09:39:11 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_pwd(void)
{
	char	*pwd;

	pwd = NULL;
	// if env && if $PWD
	pwd = getcwd(pwd, sizeof(char *));
	if (pwd)
	{
		printf("%s\n", pwd);
		return (0);
	}
	return (1);
}
