/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:20:58 by trebours          #+#    #+#             */
/*   Updated: 2023/11/02 11:29:34 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	len_s2;

	i = 0;
	len_s2 = 0;
	if (!s2[i])
		return ((char *)s1);
	while (i < len && s1[i] && s2[len_s2])
	{
		if (s1[i] == s2[len_s2])
			len_s2++;
		else
		{
			i -= len_s2;
			len_s2 = 0;
		}
		i++;
	}
	if (!s2[len_s2])
		return ((char *)(s1 + (i - len_s2)));
	return (0);
}
