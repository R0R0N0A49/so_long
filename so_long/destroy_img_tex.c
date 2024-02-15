/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img_tex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:57:55 by trebours          #+#    #+#             */
/*   Updated: 2024/02/07 14:20:53 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_other(t_maps *map)
{
	mlx_delete_texture(map->tex._0);
	mlx_delete_texture(map->tex._1);
	mlx_delete_texture(map->tex._2);
	mlx_delete_texture(map->tex._3);
	mlx_delete_texture(map->tex._4);
	mlx_delete_texture(map->tex._5);
	mlx_delete_texture(map->tex._6);
	mlx_delete_texture(map->tex._7);
	mlx_delete_texture(map->tex._8);
	mlx_delete_texture(map->tex._9);
	mlx_delete_texture(map->tex.texture_4);
	mlx_delete_texture(map->tex.texture_5);
	mlx_delete_texture(map->tex.texture_6);
	mlx_delete_texture(map->tex.logo);
	mlx_delete_texture(map->tex.ghost);
	destroy_number(map);
}

void	destroy_number(t_maps *map)
{
	mlx_delete_image(map->mlx, map->img._0);
	mlx_delete_image(map->mlx, map->img._1);
	mlx_delete_image(map->mlx, map->img._2);
	mlx_delete_image(map->mlx, map->img._3);
	mlx_delete_image(map->mlx, map->img._4);
	mlx_delete_image(map->mlx, map->img._5);
	mlx_delete_image(map->mlx, map->img._6);
	mlx_delete_image(map->mlx, map->img._7);
	mlx_delete_image(map->mlx, map->img._8);
	mlx_delete_image(map->mlx, map->img._9);
}

void	destroy_texture(t_maps *map)
{
	mlx_delete_texture(map->tex.texture_a);
	mlx_delete_texture(map->tex.texture_b);
	mlx_delete_texture(map->tex.texture_c);
	mlx_delete_texture(map->tex.texture_d);
	mlx_delete_texture(map->tex.texture_e);
	mlx_delete_texture(map->tex.texture_f);
	mlx_delete_texture(map->tex.texture_g);
	mlx_delete_texture(map->tex.texture_h);
	mlx_delete_texture(map->tex.texture_i);
	mlx_delete_texture(map->tex.texture_j);
	mlx_delete_texture(map->tex.texture_k);
	mlx_delete_texture(map->tex.texture_l);
	mlx_delete_texture(map->tex.texture_m);
	mlx_delete_texture(map->tex.texture_n);
	mlx_delete_texture(map->tex.texture_o);
	mlx_delete_texture(map->tex.texture_p);
	mlx_delete_texture(map->tex.texture_0);
	mlx_delete_texture(map->tex.texture_2);
	mlx_delete_texture(map->tex.texture_3);
	mlx_delete_texture(map->tex.texture_base);
	mlx_delete_texture(map->tex.texture_left);
	mlx_delete_texture(map->tex.texture_right);
	mlx_delete_texture(map->tex.texture_botom);
	mlx_delete_texture(map->tex.texture_high);
	destroy_other(map);
}

void	destroy_img(t_maps *map)
{
	destroy_texture(map);
	mlx_delete_image(map->mlx, map->img.img_a);
	mlx_delete_image(map->mlx, map->img.img_b);
	mlx_delete_image(map->mlx, map->img.img_c);
	mlx_delete_image(map->mlx, map->img.img_d);
	mlx_delete_image(map->mlx, map->img.img_e);
	mlx_delete_image(map->mlx, map->img.img_f);
	mlx_delete_image(map->mlx, map->img.img_g);
	mlx_delete_image(map->mlx, map->img.img_h);
	mlx_delete_image(map->mlx, map->img.img_i);
	mlx_delete_image(map->mlx, map->img.img_j);
	mlx_delete_image(map->mlx, map->img.img_k);
	mlx_delete_image(map->mlx, map->img.img_l);
	mlx_delete_image(map->mlx, map->img.img_m);
	mlx_delete_image(map->mlx, map->img.img_n);
	mlx_delete_image(map->mlx, map->img.img_o);
	mlx_delete_image(map->mlx, map->img.img_p);
	mlx_delete_image(map->mlx, map->img.img_0);
	mlx_delete_image(map->mlx, map->img.img_2);
	mlx_delete_image(map->mlx, map->img.img_3);
	mlx_delete_image(map->mlx, map->img.base);
}
