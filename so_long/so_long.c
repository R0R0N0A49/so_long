/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:39:41 by trebours          #+#    #+#             */
/*   Updated: 2024/01/29 17:39:42 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

char	ft_corner_high(t_maps *parsing, int i, size_t j)
{
	if (j < parsing->len_line_map - 2 && i < parsing->len_map - 1
		&& parsing->map[i][j] == '1' && parsing->map[i][j + 1] == '1'
		&& parsing->map[i + 1][j] == '1')
	{
		if ((j == 0 && i == 0) || (j > 0 && parsing->map[i][j - 1] != '1'
			&& i == 0) || (j > 0 && parsing->map[i][j - 1] != '1' && i > 0
			&& parsing->map[i - 1][j] != '1') || (j == 0 && i > 0
			&& parsing->map[i - 1][j] != '1'))
			return ('o');
	}
	else if (j > 0 && i < parsing->len_map - 1
		&& parsing->map[i][j] == '1' && parsing->map[i][j - 1] == '1'
		&& parsing->map[i + 1][j] == '1')
	{
		if ((j == parsing->len_line_map - 2 && i == 0) || (j
				< parsing->len_line_map - 2 && parsing->map[i][j + 1] != '1'
			&& i == 0) || (j < parsing->len_line_map - 2
			&& parsing->map[i][j + 1] != '1' && i > 0
			&& parsing->map[i - 1][j] != '1') || (j == parsing->len_line_map - 2 && i > 0
			&& parsing->map[i - 1][j] != '1'))
			return ('p');
	}
	return ('1');
}

char	ft_corner_botom(t_maps *parsing, int i, size_t j, char c)
{
	if (j < parsing->len_line_map - 2 && i > 0 && parsing->map[i][j] == c
		&& parsing->map[i][j + 1] == c && parsing->map[i - 1][j] == c)
	{
		if ((j == 0 && i == parsing->len_map - 1) || (j > 0
			&& parsing->map[i][j - 1] != c && i == parsing->len_map - 1) || (j
			> 0 && parsing->map[i][j - 1] != c && i < parsing->len_map - 1
			&& parsing->map[i + 1][j] != c) || (j == 0 && i < parsing->len_map
			- 1 && parsing->map[i + 1][j] != c))
			return ('m');
	}
	else if (j > 0 && i > 0 && parsing->map[i][j] == c
		&& parsing->map[i][j - 1] == c && parsing->map[i - 1][j] == c)
	{
		if ((j == parsing->len_line_map - 2 && i == parsing->len_map - 1)
			|| (j < parsing->len_line_map - 2 && parsing->map[i][j + 1] != c
			&& i == parsing->len_map - 1) || (j < parsing->len_line_map - 2
			&& parsing->map[i][j + 1] != c && i < parsing->len_map - 1
			&& parsing->map[i + 1][j] != c) || (j == parsing->len_line_map - 2
			&& i < parsing->len_map - 1
			&& parsing->map[i + 1][j] != c))
			return ('n');
	}
	return ('1');
}

char	ft_line(t_maps *parsing, int i, size_t j, char c)
{
	if (parsing->map[i][j] == c && ((j > parsing->len_line_map - 2 && parsing->map[i][j + 1] == c) || (j > 0 && parsing->map[i][j - 1] == c)))
		return ('b');
	else if (parsing->map[i][j] == c && (j < parsing->len_line_map - 2 && parsing->map[i][j + 1] != c)
		&& (j > 0 && parsing->map[i][j - 1] != c) && (i < parsing->len_map - 1 && parsing->map[i + 1][j] != c)
		&& (i > 0 && parsing->map[i - 1][j] != c))
		return ('c');
	return ('a');
}

char	choise_char(t_maps *parsing, int i, size_t j)
{
	char	rsl;
	const char	c = '1';

	rsl = ft_corner_high(parsing, i, j);
	if (rsl == '1')
		rsl = ft_corner_botom(parsing, i, j, c);
	if (rsl == '1')
		rsl = ft_line(parsing, i, j, c);
	return (rsl);
}

char	*ft_malloc_line(t_maps *parsing, int i)
{
	char	*result;
	size_t	j;

	result = malloc(parsing->len_line_map * sizeof(char));
	j = 0;
	while (parsing->map[i][j] != '\n')
	{
		if (parsing->map[i][j] == '1')
			result[j] = choise_char(parsing, i, j);
		else
			result[j] = parsing->map[i][j];
		j++;
	}
	result[j] = 0;
	return (result);
}

//cree une nouvelle map en remplasent les 1 par d'autre nombre
void	final_map(t_maps *parsing)
{
	char	**map_final;
	int		i;

	if (parsing->map[1][1] == '1')
		parsing->map[0][0] = '0';
	if (parsing->map[1][parsing->len_line_map - 3] == '1')
		parsing->map[0][parsing->len_line_map - 2] = '0';
	if (parsing->map[parsing->len_map - 2][1] == '1')
		parsing->map[parsing->len_map - 1][0] = '0';
	if (parsing->map[parsing->len_map - 2][parsing->len_line_map - 3] == '1')
		parsing->map[parsing->len_map - 1][parsing->len_line_map - 2] = '0';
	map_final = malloc((parsing->len_map + 1) * sizeof(char *));
	if (!map_final)
		ft_error(parsing, "error malloc");
	i = 0;
	while (i < parsing->len_map)
	{
		map_final[i] = ft_malloc_line(parsing, i);
		i++;
	}
	map_final[i] = NULL;
	ft_free_map(parsing->map);
	parsing->map = map_final;
}

static void error(void)
{
	ft_printf("%s", (mlx_strerror(mlx_errno)));
	exit(EXIT_FAILURE);
}

int32_t	ft_test_mlx(t_maps *map)
{
	// Start mlx
	int	i;
	int	j;
	mlx_t* mlx = mlx_init((map->len_line_map - 1) * 32, (map->len_map) * 32, "Test", false);
	if (!mlx)
        error();

	// Try to load the file
	mlx_texture_t* texture_a = mlx_load_png("../tile_so_long/wall_vertical.png");
	mlx_texture_t* texture_b = mlx_load_png("../tile_so_long/wall_horizontal.png");
	mlx_texture_t* texture_c = mlx_load_png("../tile_so_long/wall_alone.png");
	mlx_texture_t* texture_o = mlx_load_png("../tile_so_long/corner_high_left.png");
	mlx_texture_t* texture_p = mlx_load_png("../tile_so_long/corner_high_right.png");
	mlx_texture_t* texture_m = mlx_load_png("../tile_so_long/corner_botom_left.png");
	mlx_texture_t* texture_n = mlx_load_png("../tile_so_long/corner_botom_right.png");
	mlx_texture_t* texture_0 = mlx_load_png("../tile_so_long/floor.png");
	mlx_texture_t* texture_P = mlx_load_png("../tile_so_long/mouse_left.png");
	mlx_texture_t* texture_E = mlx_load_png("../tile_so_long/banana.png");
	mlx_texture_t* texture_C = mlx_load_png("../tile_so_long/apple.png");
		
	
	// Convert texture to a displayable image
	mlx_image_t* img_a = mlx_texture_to_image(mlx, texture_a);
	mlx_image_t* img_b = mlx_texture_to_image(mlx, texture_b);
	mlx_image_t* img_c = mlx_texture_to_image(mlx, texture_c);
	mlx_image_t* img_o = mlx_texture_to_image(mlx, texture_o);
	mlx_image_t* img_p = mlx_texture_to_image(mlx, texture_p);
	mlx_image_t* img_m = mlx_texture_to_image(mlx, texture_m);
	mlx_image_t* img_n = mlx_texture_to_image(mlx, texture_n);
	mlx_image_t* img_0 = mlx_texture_to_image(mlx, texture_0);
	mlx_image_t* img_E = mlx_texture_to_image(mlx, texture_E);
	mlx_image_t* img_C = mlx_texture_to_image(mlx, texture_C);
	mlx_image_t* img_P = mlx_texture_to_image(mlx, texture_P);

	// Display the image
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'a')
				mlx_image_to_window(mlx, img_a, (j*32), (i*32));
			else if (map->map[i][j] == 'b')
				mlx_image_to_window(mlx, img_b, (j*32), (i*32));
			else if (map->map[i][j] == 'c')
				mlx_image_to_window(mlx, img_c, (j*32), (i*32));
			else if (map->map[i][j] == 'o')
				mlx_image_to_window(mlx, img_o, (j*32), (i*32));
			else if (map->map[i][j] == 'p')
				mlx_image_to_window(mlx, img_p, (j*32), (i*32));
			else if (map->map[i][j] == 'm')
				mlx_image_to_window(mlx, img_m, (j*32), (i*32));
			else if (map->map[i][j] == 'n')
				mlx_image_to_window(mlx, img_n, (j*32), (i*32));
			else if (map->map[i][j] == '0' || map->map[i][j] == 'P' || map->map[i][j] == 'E' || map->map[i][j] == 'C')
				mlx_image_to_window(mlx, img_0, (j*32), (i*32));
			if (map->map[i][j] == 'P')
				mlx_image_to_window(mlx, img_P, (j*32), (i*32));
			else if (map->map[i][j] == 'E')
				mlx_image_to_window(mlx, img_E, (j*32), (i*32));
			else if (map->map[i][j] == 'C')
				mlx_image_to_window(mlx, img_C, (j*32), (i*32));
			j++;
		}
		i++;
	}

	mlx_loop(mlx);

	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	mlx_delete_image(mlx, img_a);
	mlx_delete_image(mlx, img_b);
	mlx_delete_image(mlx, img_m);
	mlx_delete_image(mlx, img_p);
	mlx_delete_image(mlx, img_o);
	mlx_delete_image(mlx, img_0);

	mlx_delete_texture(texture_a);
	mlx_delete_texture(texture_b);
	mlx_delete_texture(texture_o);
	mlx_delete_texture(texture_p);
	mlx_delete_texture(texture_m);
	mlx_delete_texture(texture_0);
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
	final_map(&parsing);
	int	j = 0;
	while (parsing.map[j])
	{
		ft_printf("%s\n", parsing.map[j]);
		j++;
	}
	
	ft_test_mlx(&parsing);
	ft_free_map(parsing.map);
	return (0);
}
