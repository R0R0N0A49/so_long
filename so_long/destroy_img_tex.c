/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img_tex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:57:55 by trebours          #+#    #+#             */
/*   Updated: 2024/02/02 13:58:24 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	mlx_delete_texture(loaded->texture_2);
	mlx_delete_texture(loaded->texture_3);
	mlx_delete_texture(loaded->texture_base);
}

void	destroy_img(t_image *load, t_texture *loaded)
{
	destroy_texture(loaded);
	mlx_delete_image(load->mlx, load->img_a);
	mlx_delete_image(load->mlx, load->img_b);
	mlx_delete_image(load->mlx, load->img_c);
	mlx_delete_image(load->mlx, load->img_d);
	mlx_delete_image(load->mlx, load->img_e);
	mlx_delete_image(load->mlx, load->img_f);
	mlx_delete_image(load->mlx, load->img_g);
	mlx_delete_image(load->mlx, load->img_h);
	mlx_delete_image(load->mlx, load->img_i);
	mlx_delete_image(load->mlx, load->img_j);
	mlx_delete_image(load->mlx, load->img_k);
	mlx_delete_image(load->mlx, load->img_l);
	mlx_delete_image(load->mlx, load->img_m);
	mlx_delete_image(load->mlx, load->img_n);
	mlx_delete_image(load->mlx, load->img_o);
	mlx_delete_image(load->mlx, load->img_p);
	mlx_delete_image(load->mlx, load->img_0);
	mlx_delete_image(load->mlx, load->img_2);
	mlx_delete_image(load->mlx, load->img_3);
	mlx_delete_image(load->mlx, load->base);
}
