/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:26:32 by trebours          #+#    #+#             */
/*   Updated: 2024/02/14 13:52:26 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	moving(t_maps *map, int i, int mouv)
{
	if (i)
	{
		mlx_image_to_window(map->mlx, map->img.img_0,
			(map->y * map->size), (map->x * map->size));
		map->nmb_obj -= 1;
		display_obj(map);
	}
	if (map->map[map->x][map->y] != 'E')
		map->map[map->x][map->y] = 'P';
	ft_ghost_move(map);
	map->move = mouv;
	map->nmb_move++;
	display_number(map);
	map->is_anime = 1;
	map->is_moving = 1;
}

void	left(t_maps *map)
{
	map->is_moving = 0;
	if (map->map[map->x][map->y] != 'E')
		map->map[map->x][map->y] = '0';
	if ((map->map[map->x][map->y - 1] == '0'
		|| map->map[map->x][map->y - 1] == 'P'))
	{
		map->y -= 1;
		moving(map, 0, 1);
	}
	else if (map->map[map->x][map->y - 1] == 'E')
	{
		map->y -= 1;
		moving(map, 0, 1);
		if (map->nmb_obj == 0)
			victory(*map->mlx, map);
	}
	else if (map->map[map->x][map->y - 1] == 'C')
	{
		map->y -= 1;
		moving(map, 1, 1);
		ft_printf("Colectible = %d\n", map->nmb_obj);
	}
	else if (map->map[map->x][map->y - 1] == 'F')
		death(map);
}

void	right(t_maps *map)
{
	map->is_moving = 0;
	if (map->map[map->x][map->y] != 'E')
		map->map[map->x][map->y] = '0';
	if ((map->map[map->x][map->y + 1] == '0'
		|| map->map[map->x][map->y + 1] == 'P'))
	{
		map->y += 1;
		moving(map, 0, 2);
	}
	else if (map->map[map->x][map->y + 1] == 'E')
	{
		map->y += 1;
		moving(map, 0, 2);
		if (map->nmb_obj == 0)
			victory(*map->mlx, map);
	}
	else if (map->map[map->x][map->y + 1] == 'C')
	{
		map->y += 1;
		moving(map, 1, 2);
		ft_printf("Colectible = %d\n", map->nmb_obj);
	}
	else if (map->map[map->x][map->y + 1] == 'F')
		death(map);
}

void	botom(t_maps *map)
{
	map->is_moving = 0;
	if (map->map[map->x][map->y] != 'E')
		map->map[map->x][map->y] = '0';
	if ((map->map[map->x + 1][map->y] == '0'
		|| map->map[map->x + 1][map->y] == 'P'))
	{
		map->x += 1;
		moving(map, 0, 3);
	}
	else if (map->map[map->x + 1][map->y] == 'E')
	{
		map->x += 1;
		moving(map, 0, 3);
		if (map->nmb_obj == 0)
			victory(*map->mlx, map);
	}
	else if (map->map[map->x + 1][map->y] == 'C')
	{
		map->x += 1;
		moving(map, 1, 3);
		ft_printf("Colectible = %d\n", map->nmb_obj);
	}
	else if (map->map[map->x + 1][map->y] == 'F')
		death(map);
}

void	high(t_maps *map)
{
	map->is_moving = 0;
	if (map->map[map->x][map->y] != 'E')
		map->map[map->x][map->y] = '0';
	if ((map->map[map->x - 1][map->y] == '0'
		|| map->map[map->x - 1][map->y] == 'P'))
	{
		map->x -= 1;
		moving(map, 0, 4);
	}
	else if (map->map[map->x - 1][map->y] == 'E')
	{
		map->x -= 1;
		moving(map, 0, 4);
		if (map->nmb_obj == 0)
			victory(*map->mlx, map);
	}
	else if (map->map[map->x - 1][map->y] == 'C')
	{
		map->x -= 1;
		moving(map, 1, 4);
		ft_printf("Colectible = %d\n", map->nmb_obj);
	}
	else if (map->map[map->x - 1][map->y] == 'F')
		death(map);
}
