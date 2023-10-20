/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:14:12 by adube             #+#    #+#             */
/*   Updated: 2023/10/20 11:00:20 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// dots sera mis dans le parting
int	ft_cd(char *path)
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
	if (chdir(path) == -1)
		printf("error"); // creer fonction erreur
	return (0);
}