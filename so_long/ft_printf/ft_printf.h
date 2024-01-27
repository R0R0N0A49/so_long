/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:23:16 by trebours          #+#    #+#             */
/*   Updated: 2024/01/26 09:30:13 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *src, ...);
int		ft_putnbr_base(int n, int base);
int		ft_putstr(char *s, int fd);
int		ft_type(const char src, va_list param);
int		ft_putnbr_usgd(unsigned int n, int fd, char *charbase);
int		ft_putnbr_ll(unsigned long long n, int fd, char *charbase);

#endif
