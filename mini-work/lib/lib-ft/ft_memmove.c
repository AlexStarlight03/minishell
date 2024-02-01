/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <marvin@42quebec.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:52:41 by adube             #+#    #+#             */
/*   Updated: 2022/11/30 13:51:25 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*nsrc;
	unsigned char	*ndest;
	size_t			i;

	if (!src || !dest)
		return (0);
	nsrc = (unsigned char *)src;
	ndest = (unsigned char *)dest;
	i = 0;
	if (nsrc < ndest)
	{
		while (n-- > 0)
			ndest[n] = nsrc[n];
	}
	else if (nsrc > ndest)
	{
		while (i < n)
		{
			ndest[i] = nsrc[i];
			i++;
		}
	}
	return (dest);
}
