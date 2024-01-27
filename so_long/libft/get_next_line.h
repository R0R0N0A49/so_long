/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:55:08 by trebours          #+#    #+#             */
/*   Updated: 2023/11/13 10:55:11 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
//# include "libft.h"

char	*get_next_line(int fd);
//char	*ft_strjoin(char *buf, char *result, int t);
int		ft_verif(char *result);
char	*ft_cutting(char *result, char *buf);
int		ft_strlen_gnl(char *src);

#endif
