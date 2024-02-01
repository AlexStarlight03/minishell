/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <marvin@42quebec.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:11:11 by adube             #+#    #+#             */
/*   Updated: 2022/11/30 13:44:09 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!src || !dest)
		return (0);
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
				dest[i] = src[i];
				i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
