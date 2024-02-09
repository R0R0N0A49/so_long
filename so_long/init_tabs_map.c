/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tabs_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 08:40:39 by trebours          #+#    #+#             */
/*   Updated: 2024/02/08 11:07:36 by trebours         ###   ########.fr       */
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
	close(fd);
	return (len);
}

int	init_map(t_maps *parsing, int len)
{
	int	fd;
	int	i;

	parsing->map = NULL;
	if (len == 0)
		parsing->len_map = ft_strlen_tabs(parsing->file_maps);
	else
		parsing->len_map = len;
	fd = open(parsing->file_maps, O_APPEND | O_RDONLY);
	if (fd < 0)
		return (1);
	parsing->map = malloc((parsing->len_map + 1) * sizeof(char *));
	i = 0;
	while (i < parsing->len_map)
	{
		parsing->map[i] = get_next_line(fd);
		i++;
	}
	parsing->map[i] = NULL;
	close(fd);
	return (0);
}

static char	ghost(void)
{
	if ((rand() % 100) < 2)
		return ('F');
	return ('0');
}

char	*ft_malloc_line(t_maps *parsing, int i)
{
	char	*result;
	size_t	j;

	result = malloc(parsing->len_line_map * sizeof(char));
	j = 0;
	while (parsing->map[i][j] != '\n')
	{
		if (parsing->map[i][j] == '1')
			result[j] = choice_char(parsing, i, j);
		else if (parsing->map[i][j] == '0')
			result[j] = ghost();
		else
			result[j] = parsing->map[i][j];
		if (result[j] == 'F')
			save_ghost(parsing, i, j);
		j++;
	}
	result[j] = 0;
	return (result);
}

void	final_map(t_maps *parsing)
{
	char	**map_final;
	int		i;

	map_final = malloc((parsing->len_map + 1) * sizeof(char *));
	if (!map_final)
		ft_error(parsing, "error malloc");
	i = 0;
	while (i < parsing->len_map)
	{
		map_final[i] = ft_malloc_line(parsing, i);
		i++;
	}
	map_final[i] = NULL;
	ft_free_map(parsing->map);
	parsing->map = map_final;
}
