/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <marvin@42quebec.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:00:17 by adube             #+#    #+#             */
/*   Updated: 2022/11/30 14:55:22 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_words(char const *str, char c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != c && str[i] != '\0')
			res += 1;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (res);
}

static char	*ft_new_word(char const *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc(end - start + 1, sizeof(char));
	if (word == NULL)
		return (NULL);
	while (start < end)
		word[i++] = str[start++];
	return (word);
}

static char	**ft_free(char **tab, int j)
{
	while (j--)
		free(tab[j]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		l;
	int		start;
	int		j;
	char	**tab;

	l = 0;
	j = 0;
	if (!s)
		return (NULL);
	tab = ft_calloc(nb_words(s, c) + 1, sizeof(char *));
	if (tab == NULL)
		return (NULL);
	while (s[l] != '\0' && nb_words(s, c) != 0 && j < nb_words(s, c))
	{
		while (s[l] == c && s[l] != '\0')
			l++;
		start = l;
		while (s[l] != c && s[l] != '\0')
			l++;
		tab[j] = ft_new_word(s, start, l);
		if (!tab[j])
			return (ft_free(tab, j));
		j++;
	}
	return (tab);
}
