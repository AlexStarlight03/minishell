/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <marvin@42quebec.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:56:55 by adube             #+#    #+#             */
/*   Updated: 2022/11/30 13:51:57 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	if (!s)
		return (0);
	ptr = (unsigned char *)s;
	i = 0;
	while (n-- > 0)
	{
		if (ptr[i] == (unsigned char)c)
			return (&(ptr[i]));
		i++;
	}
	return (0);
}
