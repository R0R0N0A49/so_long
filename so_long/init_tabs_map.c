/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tabs_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 08:40:39 by trebours          #+#    #+#             */
/*   Updated: 2024/01/27 11:04:55 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_strlen_tabs(char *file)
{
	int		len;
	int		fd;
	char	*ligne;

	len = 0;
	fd = open(file, O_APPEND | O_RDONLY);
	ligne = get_next_line(fd);
	while (ligne)
	{
		free(ligne);
		len++;
		ligne = get_next_line(fd);
	}
	return (len);
}

void	init_map(t_maps *parsing)
{
	int	fd;
	int	i;

	parsing->len_map = ft_strlen_tabs(parsing->file_maps);
	fd = open(parsing->file_maps, O_APPEND | O_RDONLY);
	if (fd < 0)
		return ;
	parsing->map = malloc((parsing->len_map + 1) * sizeof(char *));
	i = 0;
	while (i < parsing->len_map)
	{
		parsing->map[i] = get_next_line(fd);
		i++;
	}
	parsing->map[i] = NULL;
	close(fd);
}
