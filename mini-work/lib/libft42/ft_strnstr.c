/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <marvin@42quebec.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:04:20 by adube             #+#    #+#             */
/*   Updated: 2022/11/30 15:13:10 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	y;

	y = 0;
	if (!big)
		return (0);
	if (*little == '\0')
		return ((char *)big);
	while (big[y] && ft_strlen(little) <= len)
	{
		i = 0;
		while (little[i] == big[y + i] && (y + i) < len && little[i] != '\0')
			i++;
		if (little[i] == '\0')
			return ((char *)&big[y]);
		y++;
	}
	return (0);
}
