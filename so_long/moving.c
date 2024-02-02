/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:26:32 by trebours          #+#    #+#             */
/*   Updated: 2024/02/02 13:51:34 by trebours         ###   ########.fr       */
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
		map->map[map->x][map->y] = '0';
	}
	mlx_delete_image(map->mlx, map->img.base);
	mlx_delete_image(map->mlx, map->img.left);
	mlx_delete_image(map->mlx, map->img.right);
	mlx_delete_image(map->mlx, map->img.botom);
	mlx_delete_image(map->mlx, map->img.high);
	display_mouv(map, mouv);
	map->nmb_move++;
	ft_printf("nombre de mouvement = %d\n", map->nmb_move);
}

void	left(t_maps *map)
{
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
}

void	right(t_maps *map)
{
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
}

void	botom(t_maps *map)
{
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
}

void	high(t_maps *map)
{
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
}
