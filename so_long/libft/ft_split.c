/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:06:25 by trebours          #+#    #+#             */
/*   Updated: 2023/11/04 14:52:05 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
	if (!s[i])
		return (0);
	if (s[i] == c)
	{
		if (s[ft_strlen(s) - 1] != c)
			j = 1;
		i++;
	}
	else if (s[ft_strlen(s) - 1] != c)
		j = 1;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			j++;
		i++;
	}
	return (j);
}

size_t	ft_lenword(const char *s, char chr)
{
	size_t	i;

	i = 0;
	while (s[i] != chr && s[i])
		i++;
	return (i);
}

static char	*ft_strdup_mod(const char *s, char chr)
{
	char	*rsl;
	size_t	len_s;
	int		i;

	i = 0;
	len_s = ft_lenword(s, chr);
	rsl = (char *)ft_calloc((len_s + 1), sizeof(char));
	if (rsl == 0)
		return (0);
	while (s[i] && s[i] != chr)
	{
		rsl[i] = s[i];
		i++;
	}
	return (rsl);
}

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	tab = ft_calloc((ft_count(s, c) + 1), sizeof(char *));
	if (!tab)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			tab[j++] = ft_strdup_mod(&s[i], c);
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (tab);
}
