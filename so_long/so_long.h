/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:17:33 by trebours          #+#    #+#             */
/*   Updated: 2024/01/31 14:31:50 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "MLX42/include/MLX42/MLX42.h"

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
	mlx_texture_t	*texture_1;
	mlx_texture_t	*texture_2;
	mlx_texture_t	*texture_3;
	mlx_texture_t	*logo;
}t_texture;

typedef struct s_image
{
	mlx_t		*mlx;
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
	mlx_image_t	*img_1;
	mlx_image_t	*img_2;
	mlx_image_t	*img_3;
}t_image;

typedef struct s_maps
{
	mlx_t		*mlx;
	t_image		loaded_img;
	t_texture	loaded_tex;
	char		**map;
	size_t		len_line_map;
	char		*file_maps;
	int			len_map;
	int			nmb_obj;
	int			nmb_move;
	int			x;
	int			y;
	int			size;
}t_maps;

void	left(t_maps *map);
void	high(t_maps *map);
void	right(t_maps *map);
void	botom(t_maps *map);
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
char	choice_char(t_maps *parsing, int i, size_t j);
void	display_a_l(char c, t_image *loaded_img, int *i, int size);
void	display_o_3(char c, t_image *loaded_img, int *i, int size);
int		loop_verif_char(char *src, const char c, t_maps *parsing, int i);
void	init_image(mlx_t *mlx, t_image *load, t_texture *loaded, int size);
void	destroy_img(mlx_t *mlx, t_image *loaded, t_texture *loaded_texture);

#endif