/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmb_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:00:51 by trebours          #+#    #+#             */
/*   Updated: 2024/02/16 10:27:33 by trebours         ###   ########.fr       */
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

void	init_tex_number(t_texture *texture)
{
		texture->_0 = mlx_load_png("number/0.png");
		texture->_1 = mlx_load_png("number/1.png");
		texture->_2 = mlx_load_png("number/2.png");
		texture->_3 = mlx_load_png("number/3.png");
		texture->_4 = mlx_load_png("number/4.png");
		texture->_5 = mlx_load_png("number/5.png");
		texture->_6 = mlx_load_png("number/6.png");
		texture->_7 = mlx_load_png("number/7.png");
		texture->_8 = mlx_load_png("number/8.png");
		texture->_9 = mlx_load_png("number/9.png");
		texture->banana = mlx_load_png("number/banana.png");
		texture->slash = mlx_load_png("number/slash.png");
}

void	init_number(t_image *image, t_texture *texture, int secu)
{
	if (secu)
		init_tex_number(texture);
	image->_0 = mlx_texture_to_image(image->mlx, texture->_0);
	image->_1 = mlx_texture_to_image(image->mlx, texture->_1);
	image->_2 = mlx_texture_to_image(image->mlx, texture->_2);
	image->_3 = mlx_texture_to_image(image->mlx, texture->_3);
	image->_4 = mlx_texture_to_image(image->mlx, texture->_4);
	image->_5 = mlx_texture_to_image(image->mlx, texture->_5);
	image->_6 = mlx_texture_to_image(image->mlx, texture->_6);
	image->_7 = mlx_texture_to_image(image->mlx, texture->_7);
	image->_8 = mlx_texture_to_image(image->mlx, texture->_8);
	image->_9 = mlx_texture_to_image(image->mlx, texture->_9);
	image->banana = mlx_texture_to_image(image->mlx, texture->banana);
	image->slash = mlx_texture_to_image(image->mlx, texture->slash);
}

void	display_0_to_9(t_maps *map, int nmb, int y)
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
	destroy_number(map);
	init_number(&map->img, &map->tex, 0);
	display_obj(map);
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
