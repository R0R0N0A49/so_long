/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:00:51 by trebours          #+#    #+#             */
/*   Updated: 2024/02/08 11:44:37 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_last_line(t_maps *map)
{
	size_t	i;
	int		size;

	i = 0;
	size = map->size;
	while (i < map->len_line_map - 1)
	{
		i *= size;
		mlx_image_to_window(map->mlx, map->img.img_0, i, map->len_map * size);
		i = (i / size) + 1;
	}
}

static void	display_0_to_9(t_maps *map, int nmb, int y)
{
	int	size;

	size = map->size;
	if (nmb == 0)
		mlx_image_to_window(map->mlx, map->img._0, y * 32, map->len_map * size);
	else if (nmb == 1)
		mlx_image_to_window(map->mlx, map->img._1, y * 32, map->len_map * size);
	else if (nmb == 2)
		mlx_image_to_window(map->mlx, map->img._2, y * 32, map->len_map * size);
	else if (nmb == 3)
		mlx_image_to_window(map->mlx, map->img._3, y * 32, map->len_map * size);
	else if (nmb == 4)
		mlx_image_to_window(map->mlx, map->img._4, y * 32, map->len_map * size);
	else if (nmb == 5)
		mlx_image_to_window(map->mlx, map->img._5, y * 32, map->len_map * size);
	else if (nmb == 6)
		mlx_image_to_window(map->mlx, map->img._6, y * 32, map->len_map * size);
	else if (nmb == 7)
		mlx_image_to_window(map->mlx, map->img._7, y * 32, map->len_map * size);
	else if (nmb == 8)
		mlx_image_to_window(map->mlx, map->img._8, y * 32, map->len_map * size);
	else if (nmb == 9)
		mlx_image_to_window(map->mlx, map->img._9, y * 32, map->len_map * size);
}

void	display_number(t_maps *map)
{
	ft_printf("%d\n", map->nmb_move);
	destroy_number(map);
	init_number(&map->img, &map->tex, 0);
	if (map->nmb_move < 10)
		display_0_to_9(map, map->nmb_move, 0);
	else if (map->nmb_move < 100)
	{
		display_0_to_9(map, map->nmb_move / 10, 0);
		display_0_to_9(map, map->nmb_move % 10, 1);
	}
	else if (map->nmb_move < 1000)
	{
		display_0_to_9(map, map->nmb_move / 100, 0);
		display_0_to_9(map, (map->nmb_move % 100) / 10, 1);
		display_0_to_9(map, (map->nmb_move % 100) % 10, 2);
	}
	else if (map->nmb_move < 10000)
	{
		display_0_to_9(map, map->nmb_move / 1000, 0);
		display_0_to_9(map, (map->nmb_move % 1000) / 100, 1);
		display_0_to_9(map, ((map->nmb_move % 1000) % 100) / 10, 2);
		display_0_to_9(map, ((map->nmb_move % 1000) % 100) % 10, 3);
	}
}

void	display_obj(t_maps *map)
{
	char		*tmp;
	char		*total;
	char		*took;

	tmp = ft_itoa(map->save_nmb_obj);
	took = ft_itoa(map->save_nmb_obj - map->nmb_obj);
	total = ft_strjoin("/", tmp);
	if (map->title)
		free(map->title);
	map->title = ft_strjoin(took, total);
	mlx_set_window_title(map->mlx, map->title);
	free(tmp);
	free(total);
	free(took);
}
