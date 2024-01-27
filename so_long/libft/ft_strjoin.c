/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:40:45 by trebours          #+#    #+#             */
/*   Updated: 2023/11/02 16:41:49 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*rsl;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (0);
	len_s1 = 0;
	len_s2 = 0;
	rsl = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (rsl == 0)
		return (0);
	while (s2[len_s2] || s1[len_s1])
	{
		if (s1[len_s1] && len_s2 == 0)
		{
			rsl[len_s1] = s1[len_s1];
			len_s1++;
		}
		else
		{
			rsl[len_s1 + len_s2] = s2[len_s2];
			len_s2++;
		}
	}
	return (rsl);
}
