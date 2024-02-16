/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_txt_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:32:10 by trebours          #+#    #+#             */
/*   Updated: 2024/02/16 09:39:09 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_texture(t_texture *load)
{
	load->texture_a = mlx_load_png("tile_so_long/wall_vertical.png");
	load->texture_b = mlx_load_png("tile_so_long/wall_horizontal.png");
	load->texture_c = mlx_load_png("tile_so_long/wall_alone.png");
	load->texture_d = mlx_load_png("tile_so_long/cross_wall.png");
	load->texture_e = mlx_load_png("tile_so_long/t_botom.png");
	load->texture_f = mlx_load_png("tile_so_long/t_high.png");
	load->texture_g = mlx_load_png("tile_so_long/t_left.png");
	load->texture_h = mlx_load_png("tile_so_long/t_right.png");
	load->texture_j = mlx_load_png("tile_so_long/end_wall_botom.png");
	load->texture_i = mlx_load_png("tile_so_long/end_wall_high.png");
	load->texture_k = mlx_load_png("tile_so_long/end_wall_left.png");
	load->texture_l = mlx_load_png("tile_so_long/end_wall_right.png");
	load->texture_m = mlx_load_png("tile_so_long/corner_botom_left.png");
	load->texture_n = mlx_load_png("tile_so_long/corner_botom_right.png");
	load->texture_o = mlx_load_png("tile_so_long/corner_high_left.png");
	load->texture_p = mlx_load_png("tile_so_long/corner_high_right.png");
	load->texture_0 = mlx_load_png("tile_so_long/floor.png");
	load->texture_2 = mlx_load_png("tile_so_long/end.png");
	load->texture_3 = mlx_load_png("tile_so_long/apple.png");
	load->texture_4 = mlx_load_png("tile_so_long/orange.png");
	load->texture_5 = mlx_load_png("tile_so_long/cherry.png");
	load->texture_6 = mlx_load_png("tile_so_long/banana.png");
	load->ghost = mlx_load_png("tile_so_long/ghost_red.png");
	load->logo = mlx_load_png("tile_so_long/logo.png");
}

void	init_texture_32(t_texture *load)
{
	load->texture_a = mlx_load_png("tile_so_long(32)/wall_vertical.png");
	load->texture_b = mlx_load_png("tile_so_long(32)/wall_horizontal.png");
	load->texture_c = mlx_load_png("tile_so_long(32)/wall_alone.png");
	load->texture_d = mlx_load_png("tile_so_long(32)/cross_wall.png");
	load->texture_e = mlx_load_png("tile_so_long(32)/t_botom.png");
	load->texture_f = mlx_load_png("tile_so_long(32)/t_high.png");
	load->texture_g = mlx_load_png("tile_so_long(32)/t_left.png");
	load->texture_h = mlx_load_png("tile_so_long(32)/t_right.png");
	load->texture_j = mlx_load_png("tile_so_long(32)/end_wall_botom.png");
	load->texture_i = mlx_load_png("tile_so_long(32)/end_wall_high.png");
	load->texture_k = mlx_load_png("tile_so_long(32)/end_wall_left.png");
	load->texture_l = mlx_load_png("tile_so_long(32)/end_wall_right.png");
	load->texture_m = mlx_load_png("tile_so_long(32)/corner_botom_left.png");
	load->texture_n = mlx_load_png("tile_so_long(32)/corner_botom_right.png");
	load->texture_o = mlx_load_png("tile_so_long(32)/corner_high_left.png");
	load->texture_p = mlx_load_png("tile_so_long(32)/corner_high_right.png");
	load->texture_0 = mlx_load_png("tile_so_long(32)/floor.png");
	load->texture_2 = mlx_load_png("tile_so_long(32)/end.png");
	load->texture_3 = mlx_load_png("tile_so_long(32)/apple.png");
	load->texture_4 = mlx_load_png("tile_so_long(32)/orange.png");
	load->texture_5 = mlx_load_png("tile_so_long(32)/cherry.png");
	load->texture_6 = mlx_load_png("tile_so_long(32)/banana.png");
	load->ghost = mlx_load_png("tile_so_long(32)/ghost_red.png");
	load->logo = mlx_load_png("tile_so_long(32)/logo.png");
}

void	init_perso(t_image *load, t_texture *text, int size)
{
	if (size == 32)
	{
		text->texture_base = mlx_load_png("tile_so_long(32)/base_perso.png");
		text->texture_right = mlx_load_png("tile_so_long(32)/mouse_right.png");
		text->texture_left = mlx_load_png("tile_so_long(32)/mouse_left.png");
		text->texture_botom = mlx_load_png("tile_so_long(32)/mouse_botom.png");
		text->texture_high = mlx_load_png("tile_so_long(32)/mouse_high.png");
	}
	else
	{
		text->texture_base = mlx_load_png("tile_so_long/base_perso.png");
		text->texture_right = mlx_load_png("tile_so_long/mouse_right.png");
		text->texture_left = mlx_load_png("tile_so_long/mouse_left.png");
		text->texture_botom = mlx_load_png("tile_so_long/mouse_botom.png");
		text->texture_high = mlx_load_png("tile_so_long/mouse_high.png");
	}
	load->base = mlx_texture_to_image(load->mlx, text->texture_base);
	load->right = mlx_texture_to_image(load->mlx, text->texture_right);
	load->left = mlx_texture_to_image(load->mlx, text->texture_left);
	load->botom = mlx_texture_to_image(load->mlx, text->texture_botom);
	load->high = mlx_texture_to_image(load->mlx, text->texture_high);
}

void	init_image(t_image *load, t_texture *loaded, int size)
{
	load->img_a = mlx_texture_to_image(load->mlx, loaded->texture_a);
	load->img_b = mlx_texture_to_image(load->mlx, loaded->texture_b);
	load->img_c = mlx_texture_to_image(load->mlx, loaded->texture_c);
	load->img_d = mlx_texture_to_image(load->mlx, loaded->texture_d);
	load->img_e = mlx_texture_to_image(load->mlx, loaded->texture_e);
	load->img_f = mlx_texture_to_image(load->mlx, loaded->texture_f);
	load->img_g = mlx_texture_to_image(load->mlx, loaded->texture_g);
	load->img_h = mlx_texture_to_image(load->mlx, loaded->texture_h);
	load->img_i = mlx_texture_to_image(load->mlx, loaded->texture_i);
	load->img_j = mlx_texture_to_image(load->mlx, loaded->texture_j);
	load->img_k = mlx_texture_to_image(load->mlx, loaded->texture_k);
	load->img_l = mlx_texture_to_image(load->mlx, loaded->texture_l);
	load->img_m = mlx_texture_to_image(load->mlx, loaded->texture_m);
	load->img_n = mlx_texture_to_image(load->mlx, loaded->texture_n);
	load->img_o = mlx_texture_to_image(load->mlx, loaded->texture_o);
	load->img_p = mlx_texture_to_image(load->mlx, loaded->texture_p);
	load->img_0 = mlx_texture_to_image(load->mlx, loaded->texture_0);
	load->img_2 = mlx_texture_to_image(load->mlx, loaded->texture_2);
	load->img_3 = mlx_texture_to_image(load->mlx, loaded->texture_3);
	load->img_4 = mlx_texture_to_image(load->mlx, loaded->texture_4);
	load->img_5 = mlx_texture_to_image(load->mlx, loaded->texture_5);
	load->img_6 = mlx_texture_to_image(load->mlx, loaded->texture_6);
	load->ghost = mlx_texture_to_image(load->mlx, loaded->ghost);
	init_perso(load, loaded, size);
	init_number(load, loaded, 1);
}
