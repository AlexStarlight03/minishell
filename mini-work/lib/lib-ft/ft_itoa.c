/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <marvin@42quebec.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:59:53 by adube             #+#    #+#             */
/*   Updated: 2022/11/28 16:22:03 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_string_reverse(char *str, int end)
{
	int		i;
	char	temp;

	i = 0;
	if (str[0] == '-')
		i = 1;
	while (i < end)
	{
		temp = str[i];
		str[i] = str[end];
		str[end] = temp;
		i++;
		end--;
	}
	return (str);
}

static int	ft_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_special(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	else
		return (ft_strdup("-2147483648"));
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		res;

	i = 0;
	if (n == 0 || n == -2147483648)
		return (ft_special(n));
	str = ft_calloc(ft_len(n) + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[i++] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		res = n % 10;
		str[i++] = res + 48;
		n = n / 10;
	}
	str = ft_string_reverse(str, (i - 1));
	str[i] = '\0';
	return (str);
}
