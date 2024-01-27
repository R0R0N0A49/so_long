/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:02:02 by trebours          #+#    #+#             */
/*   Updated: 2023/11/04 16:52:10 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest1;
	const unsigned char	*src2;

	dest1 = dest;
	src2 = src;
	if (!src2 && !dest1)
		return (0);
	if (dest1 > src2)
	{
		while (n-- != 0)
			dest1[n] = src2[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dest1[i] = src2[i];
			i++;
		}
	}
	return (dest);
}
