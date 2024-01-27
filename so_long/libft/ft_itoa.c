/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:00:50 by trebours          #+#    #+#             */
/*   Updated: 2023/11/03 17:00:52 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	ft_sg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	int		i;
	int		sg;
	char	*rsl;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sg = ft_sg(n);
	if (n < 0)
		n *= -1;
	i = ft_count(n) + sg;
	rsl = ft_calloc(i-- + 1, sizeof(char));
	if (!rsl)
		return (0);
	while (n > 9)
	{
		rsl[i--] = (n % 10) + '0';
		n /= 10;
	}
	rsl[i] = n + '0';
	if (sg == 1)
		rsl[i - 1] = '-';
	return (rsl);
}
