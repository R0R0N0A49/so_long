/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:58:42 by trebours          #+#    #+#             */
/*   Updated: 2024/01/27 13:56:54 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_save(char *buf, char *result, int j)
{
	int	i;
	int	len;

	len = ft_strlen_gnl(&result[j]);
	i = 0;
	while (len > i)
	{
		buf[i] = result[i + j];
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		buf[i] = 0;
		i++;
	}
}

char	*ft_cutting(char *result, char *buf)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (result[i] != '\n' && result[i])
		i++;
	if (result[i] == '\n' || result[i] == 0)
		i++;
	tmp = malloc(i + 1 * sizeof(char));
	if (!tmp)
		return (0);
	while (j < i)
	{
		tmp[j] = result[j];
		j++;
	}
	tmp[j] = 0;
	ft_save(buf, result, j);
	free(result);
	return (tmp);
}
