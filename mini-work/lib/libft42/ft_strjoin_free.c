/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:32:15 by adube             #+#    #+#             */
/*   Updated: 2024/02/01 12:35:50 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *str1, char const *str2, int free_1)
{
	char	*memory_space;
	size_t	len_str1;
	size_t	len_str2;

	if (!str1 || !str2)
		return (0);
	len_str1 = ft_strlen(str1);
	len_str2 = ft_strlen(str2);
	memory_space = malloc(sizeof(char) * (len_str1 + len_str2 + 1));
	if (!memory_space)
		return (0);
	ft_memcpy(memory_space, str1, len_str1);
	if (free_1)
		free((char *)str1);
	ft_memcpy((memory_space + len_str1), str2, (len_str2 + 1));
	return (memory_space);
}