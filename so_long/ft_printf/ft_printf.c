/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:23:49 by trebours          #+#    #+#             */
/*   Updated: 2024/01/26 09:32:35 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putchar(char src)
{
	write (1, &src, 1);
	return (1);
}

int	ft_printf(const char *src, ...)
{
	int		result;
	int		i;
	va_list	param;

	result = 0;
	i = 0;
	if (!src)
		return (-1);
	va_start (param, src);
	while (src[i])
	{
		if (src[i] == '%' && src[i + 1] != '\0')
		{
			i++;
			result += ft_type(src[i], param);
		}
		else
		{
			write(1, &src[i], 1);
			result += 1;
		}
		i++;
	}
	va_end (param);
	return (result);
}

int	ft_type(const char src, va_list param)
{
	if (src == 's')
		return (ft_putstr(va_arg(param, char *), 1));
	if (src == 'c')
		return (ft_putchar(va_arg(param, int)));
	if (src == 'd')
		return (ft_putnbr_base(va_arg(param, int), 10));
	if (src == 'i')
		return (ft_putnbr_base(va_arg(param, int), 10));
	if (src == 'u')
		return (ft_putnbr_usgd(va_arg(param, unsigned int), 1, "0123456789"));
	if (src == 'x')
		return (ft_putnbr_base(va_arg(param, int), 16));
	if (src == 'X')
		return (ft_putnbr_base(va_arg(param, int), 16));
	if (src == 'p')
		return (ft_putnbr_ll(va_arg(param, unsigned long long),
				1, "0123456789abcdef"));
	if (src == '%')
		return (ft_putchar('%'));
	return (0);
}
