/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmb_obj_collct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:38:14 by trebours          #+#    #+#             */
/*   Updated: 2024/02/16 15:04:09 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_0_to_9(t_maps *map, int nmb, int y, int x)
{
	if (nmb == 0)
		mlx_image_to_window(map->mlx, map->img._0, y, x);
	else if (nmb == 1)
		mlx_image_to_window(map->mlx, map->img._1, y, x);
	else if (nmb == 2)
		mlx_image_to_window(map->mlx, map->img._2, y, x);
	else if (nmb == 3)
		mlx_image_to_window(map->mlx, map->img._3, y, x);
	else if (nmb == 4)
		mlx_image_to_window(map->mlx, map->img._4, y, x);
	else if (nmb == 5)
		mlx_image_to_window(map->mlx, map->img._5, y, x);
	else if (nmb == 6)
		mlx_image_to_window(map->mlx, map->img._6, y, x);
	else if (nmb == 7)
		mlx_image_to_window(map->mlx, map->img._7, y, x);
	else if (nmb == 8)
		mlx_image_to_window(map->mlx, map->img._8, y, x);
	else if (nmb == 9)
		mlx_image_to_window(map->mlx, map->img._9, y, x);
}

void	ft_display_max_obj(t_maps *map, int x, int y_max)
{
	if (map->save_nmb_obj < 10)
	{
		map->pos_slash = y_max - 64;
		display_0_to_9(map, map->save_nmb_obj, y_max - 32, x);
		mlx_image_to_window(map->mlx, map->img.slash, map->pos_slash, x);
	}
	else if (map->save_nmb_obj < 100)
	{
		map->pos_slash = y_max - 96;
		display_0_to_9(map, map->save_nmb_obj / 10, y_max - 64, x);
		display_0_to_9(map, map->save_nmb_obj % 10, y_max - 32, x);
		mlx_image_to_window(map->mlx, map->img.slash, map->pos_slash, x);
	}
	else if (map->save_nmb_obj < 1000)
	{
		map->pos_slash = y_max - 128;
		display_0_to_9(map, map->save_nmb_obj / 100, y_max - 96, x);
		display_0_to_9(map, (map->save_nmb_obj % 100) / 10, y_max - 64, x);
		display_0_to_9(map, (map->save_nmb_obj % 100) % 10, y_max - 32, x);
		mlx_image_to_window(map->mlx, map->img.slash, map->pos_slash, x);
	}
}

void	ft_display_obj(t_maps *map, int nmb_obj, int x_max)
{
	if (nmb_obj < 10 && map->save_nmb_obj < 10)
		display_0_to_9(map, nmb_obj, map->pos_slash - 32, x_max);
	else if (nmb_obj < 100 && map->save_nmb_obj > 10)
	{
		display_0_to_9(map, nmb_obj / 10, map->pos_slash - 64, x_max);
		display_0_to_9(map, nmb_obj % 10, map->pos_slash - 32, x_max);
	}
	else if (nmb_obj < 1000 && map->save_nmb_obj > 100)
	{
		display_0_to_9(map, nmb_obj / 100, map->pos_slash - 96, x_max);
		display_0_to_9(map, (nmb_obj % 100) / 10, map->pos_slash - 64, x_max);
		display_0_to_9(map, (nmb_obj % 100) % 10, map->pos_slash - 32, x_max);
	}
}

void	display_obj(t_maps *map)
{
	int	y;
	int	x;

	if (map->size == 64)
		y = (map->len_line_map - 2) * map->size + 32;
	else
		y = (map->len_line_map - 2) * map->size;
	x = map->len_map * map->size;
	mlx_image_to_window(map->mlx, map->img.banana, y, x);
	ft_display_max_obj(map, x, y);
	ft_display_obj(map, map->save_nmb_obj - map->nmb_obj, x);
}
