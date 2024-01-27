/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tabs_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 08:40:39 by trebours          #+#    #+#             */
/*   Updated: 2024/01/27 08:41:35 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_verif_ber(char *src)
{
	int	len_src;
	int	i;

	len_src = ft_strlen(src);
	i = 0;
	if (src[len_src - 1] != 'r')
		i++;
	if (src[len_src - 2] != 'e')
		i++;
	if (src[len_src - 3] != 'b')
		i++;
	if (src[len_src - 4] != '.')
		i++;
	if (i > 0)
	{
		ft_printf("Error\nthe file has the wrong format\n");
		exit(1);
	}
}

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

void	init_maps(t_maps *parsing)
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
