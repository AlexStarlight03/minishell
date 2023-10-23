/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:14:24 by adube             #+#    #+#             */
/*   Updated: 2023/10/23 14:25:10 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_pwd(void)
{
	char *pwd;
	// if env && if $PWD
	pwd = getcwd(pwd, sizeof(char *));
	if (pwd)
		printf("%s\n", pwd);
}

//int main(int argc, char **argv)
//{
//	ft_pwd();
//	return (0);
//}