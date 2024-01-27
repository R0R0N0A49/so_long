/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:39:41 by trebours          #+#    #+#             */
/*   Updated: 2024/01/27 17:42:43 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42/include/MLX42/MLX42.h"
#define WIDTH 512
#define HEIGHT 512

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_error(t_maps *parsing, char *error)
{
	ft_printf("Error\n%s\n", error);
	ft_free_map(parsing->map);
	exit(1);
}

static void error(void)
{
	ft_printf("%s", (mlx_strerror(mlx_errno)));
	exit(EXIT_FAILURE);
}

int32_t	ft_test_mlx(void)
{
	// Start mlx
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Test", false);
	if (!mlx)
        error();

	// Try to load the file
	mlx_texture_t* texture = mlx_load_png("../tile_so_long/wall_horizontal.png");
	mlx_texture_t* texture_1 = mlx_load_png("../tile_so_long/wall_vertical.png");
	mlx_texture_t* texture_2 = mlx_load_png("../tile_so_long/corner_high_left.png");
	mlx_texture_t* texture_3 = mlx_load_png("../tile_so_long/floor.png");
	
	if (!texture)
        error();
	
	// Convert texture to a displayable image
	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
	mlx_image_t* img_1 = mlx_texture_to_image(mlx, texture_1);
	mlx_image_t* img_2 = mlx_texture_to_image(mlx, texture_2);
	mlx_image_t* img_3 = mlx_texture_to_image(mlx, texture_3);
	if (!img)
        error();

	// Display the image
	mlx_image_to_window(mlx, img_1, 0, 32);
	mlx_image_to_window(mlx, img_2, 0, 0);
	mlx_image_to_window(mlx, img, 32, 0);
	mlx_image_to_window(mlx, img_3, 32, 32);


	mlx_loop(mlx);

	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);
	mlx_terminate(mlx);
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
	init_map(&parsing, 0);
	verif_len(&parsing);
	verif_quote(&parsing);
	verif_char(&parsing);
	ft_is_finished(&parsing);
	ft_test_mlx();
	ft_free_map(parsing.map);
	return (0);
}
