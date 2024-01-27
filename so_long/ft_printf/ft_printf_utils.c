/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:22:56 by trebours          #+#    #+#             */
/*   Updated: 2024/01/26 09:30:18 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(const char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

int	ft_putstr(char *s, int fd)
{
	int	i;

	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (ft_strlen(s));
}

int	ft_putnbr_usgd(unsigned int n, int fd, char *charbase)
{
	int	rsl;
	int	base;

	base = ft_strlen(charbase);
	rsl = 0;
	if (n > 9)
		rsl = ft_putnbr_usgd(n / base, fd, charbase);
	rsl += 1;
	n = n % base;
	write (fd, &charbase[n], 1);
	return (rsl);
}

int	ft_putnbr_ll(unsigned long long n, int fd, char *charbase)
{
	int			rsl;
	int			base;
	static int	i;

	if (!n)
	{
		write (fd, "(nil)", 5);
		return (5);
	}
	if (i++ == 0)
		write(fd, "0x", 2);
	base = 16;
	rsl = 2;
	if (n > 15)
		rsl = ft_putnbr_ll(n / base, fd, charbase);
	rsl += 1;
	n = n % base;
	write (fd, &charbase[n], 1);
	i = 0;
	return (rsl);
}

int	ft_putnbr_base(int n, int base)
{
	int		rsl;
	char	*charbase;

	charbase = "0123456789abcdefghijklmnopqrstuvwxyz\0";
	rsl = 0;
	if (base == 10 && n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (base == 10 && n < 0)
	{
		n = n * -1;
		write (1, "-", 1);
		rsl += 1;
	}
	if (n > (base - 1))
		rsl += ft_putnbr_base(n / base, base);
	rsl += 1;
	n = n % base;
	write (1, &charbase[n], 1);
	return (rsl);
}
