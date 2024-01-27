/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:46:58 by trebours          #+#    #+#             */
/*   Updated: 2024/01/27 13:56:58 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_verif(char *result)
{
	int	i;

	if (!result)
		return (0);
	i = 0;
	while (result[i])
	{
		if (result[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen_gnl(char *src)
{
	int	i;

	if (!src)
		return (0);
	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *buf, char *result, int t)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = malloc(BUFFER_SIZE + ft_strlen_gnl(result) + 1);
	if (!tmp)
		return (0);
	while (result && result[i])
	{
		tmp[i] = result[i];
		i++;
	}
	while (j < BUFFER_SIZE)
	{
		tmp[i + j] = buf[j];
		buf[j] = 0;
		j++;
	}
	tmp[i + j] = 0;
	if (t > 0)
		free(result);
	return (tmp);
}

static char	*read_finish(char *result)
{
	if (result[0] == '\0')
	{
		free (result);
		result = NULL;
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	static char	*result;
	static int	t;
	int			len_read;

	if (t > 0)
	{
		result = NULL;
		result = ft_strjoin(buf, result, 0);
	}
	while (1)
	{
		if (ft_verif(result) == 0)
		{
			len_read = read(fd, buf, BUFFER_SIZE);
			if (len_read < 0)
				return (NULL);
			result = ft_strjoin(buf, result, t++);
		}
		if (ft_verif(result) > 0)
			return (ft_cutting(result, buf));
		if (len_read == 0)
			return (read_finish(result));
	}
	return (0);
}
