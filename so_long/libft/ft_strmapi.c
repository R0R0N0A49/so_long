/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:02:14 by trebours          #+#    #+#             */
/*   Updated: 2023/11/03 18:02:15 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				i;
	unsigned int	j;
	char			*rsl;

	if (!s || !f)
		return (0);
	i = 0;
	j = ft_strlen(s);
	rsl = ft_calloc(j + 1, sizeof(char));
	if (!rsl)
		return (0);
	while (s[i])
	{
		rsl[i] = f(i, s[i]);
		i++;
	}
	return (rsl);
}
