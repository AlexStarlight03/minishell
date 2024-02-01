/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <marvin@42quebec.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:15:31 by adube             #+#    #+#             */
/*   Updated: 2022/11/30 18:42:18 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*newsrc;
	char	*newdest;

	if (!dest || !src)
		return (dest);
	newsrc = (char *)src;
	newdest = (char *)dest;
	if (!dest && !src)
		return (dest);
	while (n-- > 0)
		*(newdest++) = *(newsrc++);
	return (dest);
}
