/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmb_obj_collct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:38:14 by trebours          #+#    #+#             */
/*   Updated: 2024/02/16 10:25:15 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_display_max_obj(t_maps *map, int	x)
{
	if (map->save_nmb_obj < 10)
	{
		map->pos_slash = (map->len_line_map - 4);
		display_0_to_9(map, map->save_nmb_obj, map->len_line_map - 3);
		mlx_image_to_window(map->mlx, map->img.slash, map->pos_slash * 32, x);
	}
	else if (map->save_nmb_obj < 100)
	{
		map->pos_slash = (map->len_line_map - 5);
		display_0_to_9(map, map->save_nmb_obj / 10, map->len_line_map - 4);
		display_0_to_9(map, map->save_nmb_obj % 10, map->len_line_map - 3);
		mlx_image_to_window(map->mlx, map->img.slash, map->pos_slash * 32, x);
	}
	else if (map->save_nmb_obj < 1000)
	{
		map->pos_slash = (map->len_line_map - 6);
		display_0_to_9(map, map->save_nmb_obj / 100, map->len_line_map - 5);
		display_0_to_9(map, (map->save_nmb_obj % 100) / 10, map->len_line_map - 4);
		display_0_to_9(map, (map->save_nmb_obj % 100) % 10, map->len_line_map - 3);
		mlx_image_to_window(map->mlx, map->img.slash, map->pos_slash * 32, x);
	}
}

void	ft_display_obj(t_maps *map, int nmb_obj)
{
	if (nmb_obj < 10)
		display_0_to_9(map, nmb_obj, map->pos_slash - 1);
	else if (nmb_obj < 100)
	{
		display_0_to_9(map, nmb_obj / 10, map->pos_slash - 2);
		display_0_to_9(map, nmb_obj % 10, map->pos_slash - 1);
	}
	else if (nmb_obj < 1000)
	{
		display_0_to_9(map, nmb_obj / 100, map->pos_slash - 3);
		display_0_to_9(map, (nmb_obj % 100) / 10, map->pos_slash - 2);
		display_0_to_9(map, (nmb_obj % 100) % 10, map->pos_slash - 1);
	}
}

void	display_obj(t_maps *map)
{
	int	y;
	int	x;

	y = (map->len_line_map - 2) * 32;
	x = map->len_map * map->size;
	mlx_image_to_window(map->mlx, map->img.banana, y, x);
	ft_display_max_obj(map, x);
	ft_display_obj(map, map->save_nmb_obj - map->nmb_obj);
}
