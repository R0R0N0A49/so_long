/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:26:10 by trebours          #+#    #+#             */
/*   Updated: 2023/11/03 15:41:13 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*rsl;
	int		len_s;
	int		i;

	i = 0;
	len_s = ft_strlen((char *)s);
	rsl = (char *)malloc((len_s + 1) * sizeof(char));
	if (rsl == 0)
		return (0);
	while (s[i])
	{
		rsl[i] = s[i];
		i++;
	}
	rsl[i] = '\0';
	return (rsl);
}
