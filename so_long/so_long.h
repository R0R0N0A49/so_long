/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:17:33 by trebours          #+#    #+#             */
/*   Updated: 2024/01/30 17:25:17 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_maps
{
	char	**map;
	size_t	len_line_map;
	char	*file_maps;
	int		len_map;
	int		nmb_obj;
	int		x;
	int		y;
}t_maps;

typedef struct s_texture
{
	mlx_texture_t	*texture_a;
	mlx_texture_t	*texture_b;
	mlx_texture_t	*texture_c;
	mlx_texture_t	*texture_d;
	mlx_texture_t	*texture_e;
	mlx_texture_t	*texture_f;
	mlx_texture_t	*texture_g;
	mlx_texture_t	*texture_h;
	mlx_texture_t	*texture_j;
	mlx_texture_t	*texture_i;
	mlx_texture_t	*texture_k;
	mlx_texture_t	*texture_l;
	mlx_texture_t	*texture_m;
	mlx_texture_t	*texture_n;
	mlx_texture_t	*texture_o;
	mlx_texture_t	*texture_p;
	mlx_texture_t	*texture_0;
	mlx_texture_t	*texture_P;
	mlx_texture_t	*texture_E;
	mlx_texture_t	*texture_C;
}t_texture;

typedef struct s_image
{
	mlx_image_t	*img_a;
	mlx_image_t	*img_b;
	mlx_image_t	*img_c;
	mlx_image_t	*img_d;
	mlx_image_t	*img_e;
	mlx_image_t	*img_f;
	mlx_image_t	*img_g;
	mlx_image_t	*img_h;
	mlx_image_t	*img_i;
	mlx_image_t	*img_j;
	mlx_image_t	*img_k;
	mlx_image_t	*img_l;
	mlx_image_t	*img_m;
	mlx_image_t	*img_n;
	mlx_image_t	*img_o;
	mlx_image_t	*img_p;
	mlx_image_t	*img_0;
	mlx_image_t	*img_P;
	mlx_image_t	*img_E;
	mlx_image_t	*img_C;
}t_image;

void	ft_error_mlx(void);
void	ft_verif_ber(char *src);
void	ft_free_map(char **map);
void	verif_c(t_maps *parsing);
void	verif_len(t_maps *parsing);
void	final_map(t_maps *parsing);
void	verif_char(t_maps *parsing);
void	verif_quote(t_maps *parsing);
void	init_texture(t_texture *load);
void	ft_is_finished(t_maps *parsing);
void	destroy_texture(t_texture *loaded);
int		init_map(t_maps *parsing, int len);
void	ft_error(t_maps *parsing, char *error);
char	*ft_malloc_line(t_maps *parsing, int i);
void	destroy_img(mlx_t *mlx, t_image *loaded);
char	choice_char(t_maps *parsing, int i, size_t j);
void	init_image(mlx_t *mlx, t_image *load, t_texture *loaded);
int		loop_verif_char(char *src, const char c, t_maps *parsing, int i);

#endif