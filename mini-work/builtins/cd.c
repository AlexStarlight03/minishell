/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:14:12 by adube             #+#    #+#             */
/*   Updated: 2023/10/23 09:46:47 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../include/minishell.h"


# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <limits.h>
# include <errno.h>
# include <signal.h>

// dots sera mis dans le parting
//int	ft_cd(char *path)
// {
// 	int	x;
// 	int	y;
// 	int	z;
	
// 	x = 0;
// 	y = 1;
// 	z = 2;
// 	if (path[x] == '.') // scanner avant si path valide et quel type, penser a /..  et cd . et .././..
// 	{
// 		while (path[x] == '.' && path[y] == '.' && (path[z] == '/' || path[z] == '\0'))
// 		{
// 			x += 3;
// 			y += 3;
// 			z += 3;	
// 		}
// 		path = getenv(path[x]);
// 		else
// 			printf("error"); // creer fonction erreur
// 		}
			
// 	}	
//	if (chdir(path) == -1)
//		printf("error"); // creer fonction erreur
///	return (0);
//}

void ft_cd(char *path)
{	
	char *dir
	printf("%s", path)
	chdir(path);
}

int	main()
{
	ft_cd("..");
	return (0);
}