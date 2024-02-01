/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <marvin@42quebec.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:40:49 by adube             #+#    #+#             */
/*   Updated: 2022/11/30 13:52:11 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, unsigned long n)
{
	unsigned char	*ptr;

	if (!s)
		return (0);
	ptr = (unsigned char *)s;
	while (n-- > 0)
		*(ptr++) = (unsigned char)c;
	return (s);
}	
