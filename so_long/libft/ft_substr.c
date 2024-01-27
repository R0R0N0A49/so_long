/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:58:37 by trebours          #+#    #+#             */
/*   Updated: 2023/11/10 17:17:38 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(const char *s, size_t len)
{
	if (len > ft_strlen(s))
		return (ft_strlen(s));
	return (len);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*rsl;
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		rsl = ft_calloc(1, sizeof(char));
		if (rsl == 0)
			return (0);
	}
	else
	{
		len = ft_min(&s[start], len);
		rsl = ft_calloc((len + 1), sizeof(char));
		if (rsl == 0)
			return (0);
		while (len > i && s[start])
		{
			rsl[i] = s[start + i];
			i++;
		}
	}
	return (rsl);
}
