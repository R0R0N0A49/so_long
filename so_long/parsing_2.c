/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:56:35 by trebours          #+#    #+#             */
/*   Updated: 2024/01/27 15:10:13 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verif_c(t_maps *parsing)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (parsing->map[i])
	{
		tmp += loop_verif_char(parsing->map[i], 'C', parsing, i);
		i++;
	}
	if (tmp == 0)
		ft_error(parsing, "there are not object");
	parsing->nmb_obj = tmp;
}

void	ft_verif_path(t_maps *path, int x, int y)
{
	if (path->map[x][y] != '1' && path->map[x][y] != 'T')
		path->map[x][y] = 'T';
	if (path->map[x - 1][y] != '1' && path->map[x - 1][y] != 'T')
		ft_verif_path(path, x - 1, y);
	if (path->map[x][y - 1] != '1' && path->map[x][y - 1] != 'T')
		ft_verif_path(path, x, y - 1);
	if (path->map[x + 1][y] != '1' && path->map[x + 1][y] != 'T')
		ft_verif_path(path, x + 1, y);
	if (path->map[x][y + 1] != '1' && path->map[x][y + 1] != 'T')
		ft_verif_path(path, x, y + 1);
}

static int	verif(t_maps *path)
{
	int	i;
	int	j;

	i = 0;
	while (path->map[i])
	{
		j = 0;
		while (path->map[i][j])
		{
			if (path->map[i][j] == 'C' || path->map[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_is_finished(t_maps *parsing)
{
	t_maps	test_path;
	int		len;

	len = parsing->len_map;
	test_path.file_maps = parsing->file_maps;
	test_path.x = parsing->x;
	test_path.y = parsing->y;
	init_map(&test_path, len);
	ft_verif_path(&test_path, test_path.x, test_path.y);
	if (verif(&test_path))
	{
		ft_free_map(test_path.map);
		ft_error(parsing, "Your map is not terminable");
	}
	ft_free_map(test_path.map);
}
