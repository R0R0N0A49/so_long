/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:15:35 by trebours          #+#    #+#             */
/*   Updated: 2023/11/02 17:15:38 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	unsigned int	i;
	size_t			y;
	char			*rsl;

	if (!s1)
		return (0);
	i = 0;
	y = ft_strlen((char *)s1);
	while (ft_strchr(set, s1[i]))
		i++;
	while (ft_strrchr(set, s1[y]))
		y--;
	rsl = ft_substr(s1, i, (y - i) + 1);
	if (!rsl)
		return (0);
	return (rsl);
}
