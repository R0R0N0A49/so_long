/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:40:54 by trebours          #+#    #+#             */
/*   Updated: 2023/11/03 14:34:54 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*rsl;
	size_t		i;
	long int	size_maloc;

	size_maloc = nmemb * size;
	if (size_maloc < 0 || ((int)nmemb < 0 && (int)size < 0))
		return (0);
	i = 0;
	rsl = malloc(nmemb * size);
	if (rsl == 0)
		return (0);
	while (i < (nmemb * size))
	{
		rsl[i] = 0;
		i++;
	}
	return (rsl);
}
