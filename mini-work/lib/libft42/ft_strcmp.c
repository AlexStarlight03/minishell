/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:16:39 by adube             #+#    #+#             */
/*   Updated: 2024/03/17 21:08:20 by mchampag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] != s2[i])
		return (0);
	return (1);
}

// int	ft_strcmp(const char *s1, const char *s2)
// {
// 	int	i;

// 	i = 0;
// 	if (!s1 || !s2)
// 		return (0);
// 	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
// 			i++;
// 	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
// }
