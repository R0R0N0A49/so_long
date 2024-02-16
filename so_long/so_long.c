/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:39:41 by trebours          #+#    #+#             */
/*   Updated: 2024/02/16 11:12:12 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_maps	*map;

	(void)keydata;
	map = param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE)
		|| mlx_is_key_down(map->mlx, MLX_KEY_Q))
	{
		system("killall paplay &");
		mlx_close_window(map->mlx);
	}
	if ((mlx_is_key_down(map->mlx, MLX_KEY_W)
			|| mlx_is_key_down(map->mlx, MLX_KEY_UP)) && map->finish)
		high(map);
	if ((mlx_is_key_down(map->mlx, MLX_KEY_S)
			|| mlx_is_key_down(map->mlx, MLX_KEY_DOWN)) && map->finish)
		botom(map);
	if ((mlx_is_key_down(map->mlx, MLX_KEY_D)
			|| mlx_is_key_down(map->mlx, MLX_KEY_RIGHT)) && map->finish)
		right(map);
	if ((mlx_is_key_down(map->mlx, MLX_KEY_A)
			|| mlx_is_key_down(map->mlx, MLX_KEY_LEFT)) && map->finish)
		left(map);
}

void	init_struct(t_maps *map)
{
	map->mlx = mlx_init((map->len_line_map - 1) * map->size,
			map->len_map * map->size + 32, "so_long", false);
	map->img.mlx = map->mlx;
	if (map->size == 64)
		init_texture(&map->tex);
	else
		init_texture_32(&map->tex);
	init_image(&map->img, &map->tex, map->size);
	map->nmb_move = 0;
}

void	loop_so_long(t_maps *map, int size)
{
	int	i[2];

	i[0] = 0;
	while (map->map[i[0]])
	{
		i[1] = 0;
		while (map->map[i[0]][i[1]])
		{
			display_a_l(map->map[i[0]][i[1]], map, i, size);
			display_o_3(map->map[i[0]][i[1]], map, i, size);
			i[1]++;
		}
		i[0]++;
	}
}

void	ft_anim(void *param)
{
	t_maps		*map;
	static int	i = 0;
	static int	j = 0;

	map = param;
	if (i == 15 && map->is_anime)
		j = 1;
	if (i == 30 && map->is_anime)
		j = 0;
	if (map->is_anime)
		display_mouv(map, map->move);
	if (j == 1 && map->is_anime)
	{
		mlx_image_to_window(map->mlx, map->img.move,
			(map->y * map->size), (map->x * map->size));
	}
	else if (j == 0 && map->is_anime)
	{
		mlx_image_to_window(map->mlx, map->img.base,
			(map->y * map->size), (map->x * map->size));
	}
	if (i == 30)
		i = 0;
	i++;
}

int32_t	so_long(t_maps *map, int size)
{
	system("paplay music/pac_man.wav &");
	map->size = size;
	map->is_anime = 0;
	map->title = NULL;
	map->save_nmb_obj = map->nmb_obj;
	init_struct(map);
	mlx_set_icon(map->mlx, map->tex.logo);
	mlx_set_window_title(map->mlx, "Puck man");
	display_last_line(map);
	display_number(map);
	loop_so_long(map, size);
	display_ghost(map);
	mlx_key_hook(map->mlx, key_press, map);
	mlx_loop_hook(map->mlx, ft_anim, map);
	mlx_loop(map->mlx);
	destroy_img(map);
	free(map->title);
	if (map->ghost_x)
	{
		free(map->ghost_x);
		free(map->ghost_y);
	}
	mlx_terminate(map->mlx);
	return (EXIT_SUCCESS);
}
