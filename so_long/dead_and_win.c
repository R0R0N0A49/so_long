/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_and_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:17:21 by trebours          #+#    #+#             */
/*   Updated: 2024/02/15 16:26:23 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	victory(mlx_t mlx, t_maps *map)
{
	mlx_texture_t	*texture_a;
	mlx_image_t		*img_a;

	system("killall paplay");
	system("paplay music/win.wav &");
	map->finish = 0;
	map->is_anime = 0;
	texture_a = mlx_load_png("tile_so_long/win.png");
	img_a = mlx_texture_to_image(&mlx, texture_a);
	mlx_delete_image(map->mlx, map->img.base);
	mlx_delete_image(map->mlx, map->img.left);
	mlx_delete_image(map->mlx, map->img.right);
	mlx_delete_image(map->mlx, map->img.botom);
	mlx_delete_image(map->mlx, map->img.high);
	mlx_image_to_window(&mlx, img_a, 0, 0);
	mlx_set_window_size(&mlx, 640, 320);
	ft_printf("\n\nPress \"ESC\" for quit\n\n");
	mlx_loop(&mlx);
	mlx_delete_image(&mlx, img_a);
	mlx_delete_texture(texture_a);
	return (EXIT_SUCCESS);
}

int32_t	death(t_maps *map)
{
	mlx_texture_t	*texture_a;
	mlx_image_t		*img_a;

	system("killall paplay");
	system("paplay music/end.wav &");
	map->finish = 0;
	map->is_anime = 0;
	texture_a = mlx_load_png("tile_so_long/dead.png");
	img_a = mlx_texture_to_image(map->mlx, texture_a);
	mlx_delete_image(map->mlx, map->img.base);
	mlx_delete_image(map->mlx, map->img.left);
	mlx_delete_image(map->mlx, map->img.right);
	mlx_delete_image(map->mlx, map->img.botom);
	mlx_delete_image(map->mlx, map->img.high);
	mlx_image_to_window(map->mlx, img_a, 0, 0);
	mlx_set_window_size(map->mlx, 640, 320);
	ft_printf("\n\nPress \"ESC\" for quit\n\n");
	mlx_loop(map->mlx);
	mlx_delete_image(map->mlx, img_a);
	mlx_delete_texture(texture_a);
	return (EXIT_SUCCESS);
}
