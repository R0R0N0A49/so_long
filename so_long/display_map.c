/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:30:39 by trebours          #+#    #+#             */
/*   Updated: 2024/02/14 13:16:14 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_a_l(char c, t_maps *map, int *i, int size)
{
	int		x;

	x = (i[1] * size);
	if (c == 'a')
		mlx_image_to_window(map->mlx, map->img.img_a, x, (i[0] * size));
	else if (c == 'b')
		mlx_image_to_window(map->mlx, map->img.img_b, x, (i[0] * size));
	else if (c == 'c')
		mlx_image_to_window(map->mlx, map->img.img_c, x, (i[0] * size));
	else if (c == 'd')
		mlx_image_to_window(map->mlx, map->img.img_d, x, (i[0] * size));
	else if (c == 'e')
		mlx_image_to_window(map->mlx, map->img.img_e, x, (i[0] * size));
	else if (c == 'f')
		mlx_image_to_window(map->mlx, map->img.img_f, x, (i[0] * size));
	else if (c == 'g')
		mlx_image_to_window(map->mlx, map->img.img_g, x, (i[0] * size));
	else if (c == 'h')
		mlx_image_to_window(map->mlx, map->img.img_h, x, (i[0] * size));
	else if (c == 'i')
		mlx_image_to_window(map->mlx, map->img.img_i, x, (i[0] * size));
	else if (c == 'j')
		mlx_image_to_window(map->mlx, map->img.img_j, x, (i[0] * size));
}

static void	display_object(t_maps *map, int size, int *i)
{
	static int	nmb_obj = 0;
	int			x;

	x = (i[1] * size);
	if (nmb_obj == 0)
		mlx_image_to_window(map->img.mlx, map->img.img_3, x, (i[0] * size));
	if (nmb_obj == 1)
		mlx_image_to_window(map->img.mlx, map->img.img_4, x, (i[0] * size));
	if (nmb_obj == 2)
		mlx_image_to_window(map->img.mlx, map->img.img_5, x, (i[0] * size));
	if (nmb_obj == 3)
		mlx_image_to_window(map->img.mlx, map->img.img_6, x, (i[0] * size));
	nmb_obj++;
	if (nmb_obj == 4)
		nmb_obj = 0;
}

void	display_o_3(char c, t_maps *map, int *i, int size)
{
	int		x;

	x = (i[1] * size);
	if (c == 'k')
		mlx_image_to_window(map->mlx, map->img.img_k, x, (i[0] * size));
	else if (c == 'l')
		mlx_image_to_window(map->mlx, map->img.img_l, x, (i[0] * size));
	else if (c == 'o')
		mlx_image_to_window(map->mlx, map->img.img_o, x, (i[0] * size));
	else if (c == 'p')
		mlx_image_to_window(map->mlx, map->img.img_p, x, (i[0] * size));
	else if (c == 'm')
		mlx_image_to_window(map->mlx, map->img.img_m, x, (i[0] * size));
	else if (c == 'n')
		mlx_image_to_window(map->mlx, map->img.img_n, x, (i[0] * size));
	else if (c == '0' || c == 'P' || c == 'E' || c == 'C' || c == 'F')
		mlx_image_to_window(map->mlx, map->img.img_0, x, (i[0] * size));
	if (c == 'P')
		mlx_image_to_window(map->mlx, map->img.base, x, (i[0] * size));
	else if (c == 'E')
		mlx_image_to_window(map->mlx, map->img.img_2, x, (i[0] * size));
	else if (c == 'C')
		display_object(map, size, i);
}

void	display_mouv(t_maps *map, int mouv)
{
	if (mouv == 1)
	{
		map->img.base = mlx_texture_to_image(map->mlx, map->tex.texture_base);
		map->img.move = mlx_texture_to_image(map->mlx, map->tex.texture_left);
		// mlx_image_to_window(map->mlx, map->img.left,
			// (map->y * map->size), (map->x * map->size));
	}
	if (mouv == 2)
	{
		map->img.base = mlx_texture_to_image(map->mlx, map->tex.texture_base);
		map->img.move = mlx_texture_to_image(map->mlx, map->tex.texture_right);
		// mlx_image_to_window(map->mlx, map->img.right,
			// (map->y * map->size), (map->x * map->size));
	}
	if (mouv == 3)
	{
		map->img.base = mlx_texture_to_image(map->mlx, map->tex.texture_base);
		map->img.move = mlx_texture_to_image(map->mlx, map->tex.texture_botom);
		// mlx_image_to_window(map->mlx, map->img.botom,
			// (map->y * map->size), (map->x * map->size));
	}
	if (mouv == 4)
	{
		map->img.base = mlx_texture_to_image(map->mlx, map->tex.texture_base);
		map->img.move = mlx_texture_to_image(map->mlx, map->tex.texture_high);
		// mlx_image_to_window(map->mlx, map->img.high,
			// (map->y * map->size), (map->x * map->size));
	}
}

void	display_ghost(t_maps *map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	mlx_delete_image(map->mlx, map->img.ghost);
	map->img.ghost = mlx_texture_to_image(map->mlx, map->tex.ghost);
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'F')
			{
				x = i * map->size;
				y = j * map->size;
				mlx_image_to_window(map->mlx, map->img.ghost, y, x);
			}
			j++;
		}
		i++;
	}
}
