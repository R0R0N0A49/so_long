/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:03:54 by trebours          #+#    #+#             */
/*   Updated: 2023/10/31 18:03:55 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memchr(const void *s, int c, size_t n)
{
	long unsigned int	i;
	const char			*src;

	if (c > 255)
		c -= 256;
	src = s;
	i = 0;
	while (i < n)
	{
		if (src[i] == c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}
