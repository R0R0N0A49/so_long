/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_txt_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:32:10 by trebours          #+#    #+#             */
/*   Updated: 2024/01/30 16:34:24 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_texture(t_texture *load)
{
	load->texture_a = mlx_load_png("../tile_so_long/wall_vertical.png");
	load->texture_b = mlx_load_png("../tile_so_long/wall_horizontal.png");
	load->texture_c = mlx_load_png("../tile_so_long/wall_alone.png");
	load->texture_d = mlx_load_png("../tile_so_long/cross_wall.png");
	load->texture_e = mlx_load_png("../tile_so_long/t_botom.png");
	load->texture_f = mlx_load_png("../tile_so_long/t_high.png");
	load->texture_g = mlx_load_png("../tile_so_long/t_left.png");
	load->texture_h = mlx_load_png("../tile_so_long/t_right.png");
	load->texture_j = mlx_load_png("../tile_so_long/end_wall_botom.png");
	load->texture_i = mlx_load_png("../tile_so_long/end_wall_high.png");
	load->texture_k = mlx_load_png("../tile_so_long/end_wall_left.png");
	load->texture_l = mlx_load_png("../tile_so_long/end_wall_right.png");
	load->texture_m = mlx_load_png("../tile_so_long/corner_botom_left.png");
	load->texture_n = mlx_load_png("../tile_so_long/corner_botom_right.png");
	load->texture_o = mlx_load_png("../tile_so_long/corner_high_left.png");
	load->texture_p = mlx_load_png("../tile_so_long/corner_high_right.png");
	load->texture_0 = mlx_load_png("../tile_so_long/floor.png");
	load->texture_P = mlx_load_png("../tile_so_long/mouse_left.png");
	load->texture_E = mlx_load_png("../tile_so_long/banana.png");
	load->texture_C = mlx_load_png("../tile_so_long/apple.png");
}

void	init_image(mlx_t *mlx, t_image *load, t_texture *loaded)
{
	load->img_a = mlx_texture_to_image(&mlx[0], loaded->texture_a);
	load->img_b = mlx_texture_to_image(&mlx[0], loaded->texture_b);
	load->img_c = mlx_texture_to_image(&mlx[0], loaded->texture_c);
	load->img_d = mlx_texture_to_image(&mlx[0], loaded->texture_d);
	load->img_e = mlx_texture_to_image(&mlx[0], loaded->texture_e);
	load->img_f = mlx_texture_to_image(&mlx[0], loaded->texture_f);
	load->img_g = mlx_texture_to_image(&mlx[0], loaded->texture_g);
	load->img_h = mlx_texture_to_image(&mlx[0], loaded->texture_h);
	load->img_i = mlx_texture_to_image(&mlx[0], loaded->texture_i);
	load->img_j = mlx_texture_to_image(&mlx[0], loaded->texture_j);
	load->img_k = mlx_texture_to_image(&mlx[0], loaded->texture_k);
	load->img_l = mlx_texture_to_image(&mlx[0], loaded->texture_l);
	load->img_m = mlx_texture_to_image(&mlx[0], loaded->texture_m);
	load->img_n = mlx_texture_to_image(&mlx[0], loaded->texture_n);
	load->img_o = mlx_texture_to_image(&mlx[0], loaded->texture_o);
	load->img_p = mlx_texture_to_image(&mlx[0], loaded->texture_p);
	load->img_0 = mlx_texture_to_image(&mlx[0], loaded->texture_0);
	load->img_E = mlx_texture_to_image(&mlx[0], loaded->texture_E);
	load->img_C = mlx_texture_to_image(&mlx[0], loaded->texture_C);
	load->img_P = mlx_texture_to_image(&mlx[0], loaded->texture_P);
}

void	destroy_texture(t_texture *loaded)
{
	mlx_delete_texture(loaded->texture_a);
	mlx_delete_texture(loaded->texture_b);
	mlx_delete_texture(loaded->texture_c);
	mlx_delete_texture(loaded->texture_d);
	mlx_delete_texture(loaded->texture_e);
	mlx_delete_texture(loaded->texture_f);
	mlx_delete_texture(loaded->texture_g);
	mlx_delete_texture(loaded->texture_h);
	mlx_delete_texture(loaded->texture_i);
	mlx_delete_texture(loaded->texture_j);
	mlx_delete_texture(loaded->texture_k);
	mlx_delete_texture(loaded->texture_l);
	mlx_delete_texture(loaded->texture_m);
	mlx_delete_texture(loaded->texture_n);
	mlx_delete_texture(loaded->texture_o);
	mlx_delete_texture(loaded->texture_p);
	mlx_delete_texture(loaded->texture_0);
	mlx_delete_texture(loaded->texture_E);
	mlx_delete_texture(loaded->texture_C);
	mlx_delete_texture(loaded->texture_P);
}

void	destroy_img(mlx_t *mlx, t_image *loaded)
{
	mlx_delete_image(&mlx[0], loaded->img_a);
	mlx_delete_image(&mlx[0], loaded->img_b);
	mlx_delete_image(&mlx[0], loaded->img_c);
	mlx_delete_image(&mlx[0], loaded->img_d);
	mlx_delete_image(&mlx[0], loaded->img_e);
	mlx_delete_image(&mlx[0], loaded->img_f);
	mlx_delete_image(&mlx[0], loaded->img_g);
	mlx_delete_image(&mlx[0], loaded->img_h);
	mlx_delete_image(&mlx[0], loaded->img_i);
	mlx_delete_image(&mlx[0], loaded->img_j);
	mlx_delete_image(&mlx[0], loaded->img_k);
	mlx_delete_image(&mlx[0], loaded->img_l);
	mlx_delete_image(&mlx[0], loaded->img_m);
	mlx_delete_image(&mlx[0], loaded->img_n);
	mlx_delete_image(&mlx[0], loaded->img_o);
	mlx_delete_image(&mlx[0], loaded->img_p);
	mlx_delete_image(&mlx[0], loaded->img_0);
	mlx_delete_image(&mlx[0], loaded->img_E);
	mlx_delete_image(&mlx[0], loaded->img_C);
	mlx_delete_image(&mlx[0], loaded->img_P);
}