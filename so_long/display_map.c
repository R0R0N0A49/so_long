/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:30:39 by trebours          #+#    #+#             */
/*   Updated: 2024/02/02 13:50:46 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_a_l(char c, t_image *loaded_img, int *i, int size)
{
	mlx_t	*mlx;
	int		x;

	mlx = loaded_img->mlx;
	x = (i[1] * size);
	if (c == 'a')
		mlx_image_to_window(&mlx[0], loaded_img->img_a, x, (i[0] * size));
	else if (c == 'b')
		mlx_image_to_window(&mlx[0], loaded_img->img_b, x, (i[0] * size));
	else if (c == 'c')
		mlx_image_to_window(&mlx[0], loaded_img->img_c, x, (i[0] * size));
	else if (c == 'd')
		mlx_image_to_window(&mlx[0], loaded_img->img_d, x, (i[0] * size));
	else if (c == 'e')
		mlx_image_to_window(&mlx[0], loaded_img->img_e, x, (i[0] * size));
	else if (c == 'f')
		mlx_image_to_window(&mlx[0], loaded_img->img_f, x, (i[0] * size));
	else if (c == 'g')
		mlx_image_to_window(&mlx[0], loaded_img->img_g, x, (i[0] * size));
	else if (c == 'h')
		mlx_image_to_window(&mlx[0], loaded_img->img_h, x, (i[0] * size));
	else if (c == 'i')
		mlx_image_to_window(&mlx[0], loaded_img->img_i, x, (i[0] * size));
	else if (c == 'j')
		mlx_image_to_window(&mlx[0], loaded_img->img_j, x, (i[0] * size));
}

void	display_o_3(char c, t_image *loaded_img, int *i, int size)
{
	mlx_t	*mlx;
	int		x;

	mlx = loaded_img->mlx;
	x = (i[1] * size);
	if (c == 'k')
		mlx_image_to_window(&mlx[0], loaded_img->img_k, x, (i[0] * size));
	else if (c == 'l')
		mlx_image_to_window(&mlx[0], loaded_img->img_l, x, (i[0] * size));
	else if (c == 'o')
		mlx_image_to_window(&mlx[0], loaded_img->img_o, x, (i[0] * size));
	else if (c == 'p')
		mlx_image_to_window(&mlx[0], loaded_img->img_p, x, (i[0] * size));
	else if (c == 'm')
		mlx_image_to_window(&mlx[0], loaded_img->img_m, x, (i[0] * size));
	else if (c == 'n')
		mlx_image_to_window(&mlx[0], loaded_img->img_n, x, (i[0] * size));
	else if (c == '0' || c == 'P' || c == 'E' || c == 'C')
		mlx_image_to_window(&mlx[0], loaded_img->img_0, x, (i[0] * size));
	if (c == 'P')
		mlx_image_to_window(&mlx[0], loaded_img->base, x, (i[0] * size));
	else if (c == 'E')
		mlx_image_to_window(&mlx[0], loaded_img->img_2, x, (i[0] * size));
	else if (c == 'C')
		mlx_image_to_window(&mlx[0], loaded_img->img_3, x, (i[0] * size));
}

void	display_mouv(t_maps *map, int mouv)
{
	if (mouv == 1)
	{
		map->img.left = mlx_texture_to_image(map->mlx, map->tex.texture_left);
		mlx_image_to_window(map->mlx, map->img.left,
			(map->y * map->size), (map->x * map->size));
	}
	if (mouv == 2)
	{
		map->img.right = mlx_texture_to_image(map->mlx, map->tex.texture_right);
		mlx_image_to_window(map->mlx, map->img.right,
			(map->y * map->size), (map->x * map->size));
	}
	if (mouv == 3)
	{
		map->img.botom = mlx_texture_to_image(map->mlx, map->tex.texture_botom);
		mlx_image_to_window(map->mlx, map->img.botom,
			(map->y * map->size), (map->x * map->size));
	}
	if (mouv == 4)
	{
		map->img.high = mlx_texture_to_image(map->mlx, map->tex.texture_high);
		mlx_image_to_window(map->mlx, map->img.high,
			(map->y * map->size), (map->x * map->size));
	}
}
