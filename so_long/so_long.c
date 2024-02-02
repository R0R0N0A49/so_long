/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:39:41 by trebours          #+#    #+#             */
/*   Updated: 2024/02/02 13:56:52 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	victory(mlx_t mlx, t_maps *map)
{
	mlx_texture_t	*texture_a;
	mlx_image_t		*img_a;

	texture_a = mlx_load_png("tile_so_long/win.png");
	img_a = mlx_texture_to_image(&mlx, texture_a);
	mlx_delete_image(map->mlx, map->img.base);
	mlx_delete_image(map->mlx, map->img.left);
	mlx_delete_image(map->mlx, map->img.right);
	mlx_delete_image(map->mlx, map->img.botom);
	mlx_delete_image(map->mlx, map->img.high);
	mlx_image_to_window(&mlx, img_a, 0, 0);
	mlx_set_window_size(&mlx, 640, 320);
	ft_printf("\n\nPress \"esc\" for quit\n\n");
	mlx_loop(&mlx);
	mlx_delete_image(&mlx, img_a);
	mlx_delete_texture(texture_a);
	return (EXIT_SUCCESS);
}

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_maps	*map;

	(void)keydata;
	map = param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	if (mlx_is_key_down(map->mlx, MLX_KEY_W)
		|| mlx_is_key_down(map->mlx, MLX_KEY_UP))
		high(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_S)
		|| mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
		botom(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_D)
		|| mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
		right(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_A)
		|| mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
		left(map);
}

void	save_struct(t_maps *map)
{
	t_texture	loaded_texture;
	t_image		loaded_img;

	map->mlx = mlx_init((map->len_line_map - 1) * map->size,
			(map->len_map) * map->size, "so_long", false);
	loaded_img.mlx = map->mlx;
	init_image(&loaded_img, &loaded_texture, map->size);
	map->img = loaded_img;
	map->tex = loaded_texture;
	map->nmb_move = 0;
}

int32_t	so_long(t_maps *map, int size)
{
	int			i[2];

	ft_printf("Colectible = %d\n", map->nmb_obj);
	map->size = size;
	save_struct(map);
	mlx_set_icon(map->mlx, map->tex.logo);
	mlx_set_window_title(map->mlx, "Puck Man");
	i[0] = 0;
	while (map->map[i[0]])
	{
		i[1] = 0;
		while (map->map[i[0]][i[1]])
		{
			display_a_l(map->map[i[0]][i[1]], &map->img, i, size);
			display_o_3(map->map[i[0]][i[1]], &map->img, i, size);
			i[1]++;
		}
		i[0]++;
	}
	mlx_key_hook(map->mlx, key_press, map);
	mlx_loop(map->mlx);
	destroy_img(&map->img, &map->tex);
	mlx_terminate(map->mlx);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_maps	parsing;

	if (argc != 2)
	{
		ft_printf("Error\nBad imput\n");
		exit(1);
	}
	ft_verif_ber(argv[1]);
	parsing.file_maps = argv[1];
	if (init_map(&parsing, 0))
		ft_error(&parsing, "Error map");
	verif_len(&parsing);
	verif_quote(&parsing);
	verif_char(&parsing);
	ft_is_finished(&parsing);
	final_map(&parsing);
	if (parsing.len_line_map - 2 > 30 || parsing.len_map - 1 > 15)
		so_long(&parsing, 32);
	else
		so_long(&parsing, 64);
	ft_free_map(parsing.map);
	return (0);
}
