/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:13:46 by trebours          #+#    #+#             */
/*   Updated: 2024/02/16 11:31:34 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	save_ghost(t_maps *parsing, int x, int y)
{
	int			*save_y;
	int			*save_x;
	int			a;

	parsing->nmb_ghost++;
	save_y = malloc(parsing->nmb_ghost * sizeof(int));
	save_x = malloc(parsing->nmb_ghost * sizeof(int));
	if (!save_x || !save_y)
		exit(1);
	a = 0;
	while (a < parsing->nmb_ghost - 1)
	{
		save_x[a] = parsing->ghost_x[a];
		save_y[a] = parsing->ghost_y[a];
		a++;
	}
	save_x[a] = x;
	save_y[a] = y;
	if (parsing->nmb_ghost > 1)
	{
		free(parsing->ghost_x);
		free(parsing->ghost_y);
	}
	parsing->ghost_x = save_x;
	parsing->ghost_y = save_y;
}

void	move_horizontal(t_maps *map, int random_direction, int i)
{
	if (random_direction == 1)
	{
		if (map->map[map->ghost_x[i] + 1][map->ghost_y[i]] == '0')
			map->ghost_x[i]++;
		else if (map->map[map->ghost_x[i] + 1][map->ghost_y[i]] == 'P')
			death(map);
		return ;
	}
	else
	{
		if (map->map[map->ghost_x[i] - 1][map->ghost_y[i]] == '0')
			map->ghost_x[i]--;
		else if (map->map[map->ghost_x[i] - 1][map->ghost_y[i]] == 'P')
			death(map);
		return ;
	}
}

void	move_vertical(t_maps *map, int random_direction, int i)
{
	if (random_direction == 1)
	{
		if (map->map[map->ghost_x[i]][map->ghost_y[i] + 1] == '0')
			map->ghost_y[i]++;
		else if (map->map[map->ghost_x[i]][map->ghost_y[i] + 1] == 'P')
			death(map);
		return ;
	}
	else
	{
		if (map->map[map->ghost_x[i]][map->ghost_y[i] - 1] == '0')
			map->ghost_y[i]--;
		else if (map->map[map->ghost_x[i]][map->ghost_y[i] - 1] == 'P')
			death(map);
		return ;
	}
}

void	ft_ghost_move(void *param)
{
	t_maps		*map;
	int			random_direction;
	int			i;

	map = param;
	i = 0;
	while (i < map->nmb_ghost)
	{
		random_direction = rand() % 2;
		map->map[map->ghost_x[i]][map->ghost_y[i]] = '0';
		if ((rand() % 2) == 1)
			move_vertical(map, random_direction, i);
		else
			move_horizontal(map, random_direction, i);
		map->map[map->ghost_x[i]][map->ghost_y[i]] = 'F';
		i++;
	}
	display_ghost(map);
}
