/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <marvin@42quebec.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:33:38 by adube             #+#    #+#             */
/*   Updated: 2022/11/30 13:50:40 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	szdest;
	size_t	szsrc;
	size_t	i;

	i = 0;
	if (!src || !dest)
		return (0);
	szsrc = ft_strlen(src);
	szdest = ft_strlen(dest);
	if (size <= szdest)
		return (size + szsrc);
	while (szdest + i < size - 1 && src[i] != '\0')
	{
		dest[szdest + i] = src[i];
		i++;
	}
	dest[szdest + i] = '\0';
	return (szdest + szsrc);
}
