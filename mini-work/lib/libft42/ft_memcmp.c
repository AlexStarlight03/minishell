/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <marvin@42quebec.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:59:40 by adube             #+#    #+#             */
/*   Updated: 2022/11/30 13:43:49 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*ptr;
	unsigned const char	*ptr2;

	if (n == 0 || !s1 || !s2)
		return (0);
	ptr = (unsigned const char *)s1;
	ptr2 = (unsigned const char *)s2;
	while (n-- > 0)
	{
		if (*ptr != *ptr2)
			return (*ptr - *ptr2);
		ptr++;
		ptr2++;
	}
	return (0);
}
