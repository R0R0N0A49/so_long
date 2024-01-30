/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:39:41 by trebours          #+#    #+#             */
/*   Updated: 2024/01/30 17:24:43 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_a_l(mlx_t mlx, char c, t_image *loaded_img, int *i)
{
	if (c == 'a')
		mlx_image_to_window(&mlx, loaded_img->img_a, (i[1] * 32), (i[0] * 32));
	else if (c == 'b')
		mlx_image_to_window(&mlx, loaded_img->img_b, (i[1] * 32), (i[0] * 32));
	else if (c == 'c')
		mlx_image_to_window(&mlx, loaded_img->img_c, (i[1] * 32), (i[0] * 32));
	else if (c == 'd')
		mlx_image_to_window(&mlx, loaded_img->img_d, (i[1] * 32), (i[0] * 32));
	else if (c == 'e')
		mlx_image_to_window(&mlx, loaded_img->img_e, (i[1] * 32), (i[0] * 32));
	else if (c == 'f')
		mlx_image_to_window(&mlx, loaded_img->img_f, (i[1] * 32), (i[0] * 32));
	else if (c == 'g')
		mlx_image_to_window(&mlx, loaded_img->img_g, (i[1] * 32), (i[0] * 32));
	else if (c == 'h')
		mlx_image_to_window(&mlx, loaded_img->img_h, (i[1] * 32), (i[0] * 32));
	else if (c == 'i')
		mlx_image_to_window(&mlx, loaded_img->img_i, (i[1] * 32), (i[0] * 32));
	else if (c == 'j')
		mlx_image_to_window(&mlx, loaded_img->img_j, (i[1] * 32), (i[0] * 32));
	else if (c == 'k')
		mlx_image_to_window(&mlx, loaded_img->img_k, (i[1] * 32), (i[0] * 32));
	else if (c == 'l')
		mlx_image_to_window(&mlx, loaded_img->img_l, (i[1] * 32), (i[0] * 32));
	display_o_c(*mlx, c, &loaded_img, i);
}

void	display_o_c(mlx_t mlx, char c, t_image *loaded_img, int *i)
{
	if (c == 'o')
		mlx_image_to_window(&mlx, loaded_img->img_o, (i[1] * 32), (i[0] * 32));
	else if (c == 'p')
		mlx_image_to_window(&mlx, loaded_img->img_p, (i[1] * 32), (i[0] * 32));
	else if (c == 'm')
		mlx_image_to_window(&mlx, loaded_img->img_m, (i[1] * 32), (i[0] * 32));
	else if (c == 'n')
		mlx_image_to_window(&mlx, loaded_img->img_n, (i[1] * 32), (i[0] * 32));
	else if (c == '0' || c == 'P' || c == 'E' || c == 'C')
		mlx_image_to_window(&mlx, loaded_img->img_0, (i[1] * 32), (i[0] * 32));
	if (c == 'P')
		mlx_image_to_window(&mlx, loaded_img->img_P, (i[1] * 32), (i[0] * 32));
	else if (c == 'E')
		mlx_image_to_window(&mlx, loaded_img->img_E, (i[1] * 32), (i[0] * 32));
	else if (c == 'C')
		mlx_image_to_window(&mlx, loaded_img->img_C, (i[1] * 32), (i[0] * 32));
}

int32_t	ft_test_mlx(t_maps *map)
{
	int			i[2];
	t_texture	loaded_texture;
	t_image		loaded_img;
	mlx_t		*mlx;

	mlx = mlx_init((map->len_line_map - 1) * 32,
			(map->len_map) * 32, "Test", false);
	i[0] = 0;
	init_texture(&loaded_texture);
	init_image(mlx, &loaded_img, &loaded_texture);
	while (map->map[i[0]])
	{
		i[1] = 0;
		while (map->map[i[0]][i[1]])
		{
			display_a_l(*mlx, map->map[i[0]][i[1]], &loaded_img, i);
			i[1]++;
		}
		i[0]++;
	}
	mlx_loop(mlx);
	destroy_texture(&loaded_texture);
	destroy_img(mlx, &loaded_img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_maps	parsing;
	int		j;

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
	j = 0;
	while (parsing.map[j])
		ft_printf("%s\n", parsing.map[j++]);
	ft_test_mlx(&parsing);
	ft_free_map(parsing.map);
	return (0);
}
