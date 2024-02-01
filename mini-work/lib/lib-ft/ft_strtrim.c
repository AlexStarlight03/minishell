/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <marvin@42quebec.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:18:00 by adube             #+#    #+#             */
/*   Updated: 2022/11/30 13:47:22 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{	
	int		i;
	int		start;
	int		end;
	char	*ptr;

	i = 0;
	start = 0;
	if (!s1)
		return (0);
	if (s1[0] == '\0')
		return (ft_strdup(s1));
	while (ft_checkset(s1[start], set))
			start++;
	end = 0;
	while (s1[end] != '\0')
		end++;
	while (ft_checkset(s1[end - 1], set) && end > start)
		end--;
	ptr = ft_calloc(end - start + 1, 1);
	if (!ptr)
		return (NULL);
	while (start < end)
		ptr[i++] = s1[start++];
	return (ptr);
}
