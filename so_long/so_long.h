/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:17:33 by trebours          #+#    #+#             */
/*   Updated: 2024/02/16 14:37:20 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <time.h>

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
	mlx_texture_t	*texture_2;
	mlx_texture_t	*texture_3;
	mlx_texture_t	*texture_4;
	mlx_texture_t	*texture_5;
	mlx_texture_t	*texture_6;
	mlx_texture_t	*ghost;
	mlx_texture_t	*texture_base;
	mlx_texture_t	*texture_right;
	mlx_texture_t	*texture_left;
	mlx_texture_t	*texture_botom;
	mlx_texture_t	*texture_high;
	mlx_texture_t	*logo;
	mlx_texture_t	*_0;
	mlx_texture_t	*_1;
	mlx_texture_t	*_2;
	mlx_texture_t	*_3;
	mlx_texture_t	*_4;
	mlx_texture_t	*_5;
	mlx_texture_t	*_6;
	mlx_texture_t	*_7;
	mlx_texture_t	*_8;
	mlx_texture_t	*_9;
	mlx_texture_t	*banana;
	mlx_texture_t	*slash;
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
	mlx_image_t	*img_2;
	mlx_image_t	*img_3;
	mlx_image_t	*img_4;
	mlx_image_t	*img_5;
	mlx_image_t	*img_6;
	mlx_image_t	*ghost;
	mlx_image_t	*base;
	mlx_image_t	*right;
	mlx_image_t	*left;
	mlx_image_t	*botom;
	mlx_image_t	*high;
	mlx_image_t	*_0;
	mlx_image_t	*_1;
	mlx_image_t	*_2;
	mlx_image_t	*_3;
	mlx_image_t	*_4;
	mlx_image_t	*_5;
	mlx_image_t	*_6;
	mlx_image_t	*_7;
	mlx_image_t	*_8;
	mlx_image_t	*_9;
	mlx_image_t	*move;
	mlx_image_t	*banana;
	mlx_image_t	*slash;
}t_image;

typedef struct s_maps
{
	mlx_t		*mlx;
	t_image		img;
	t_texture	tex;
	size_t		len_line_map;
	char		**map;
	int			finish;
	char		*file_maps;
	char		*title;
	int			len_map;
	int			nmb_obj;
	int			save_nmb_obj;
	int			pos_slash;
	int			nmb_move;
	int			x;
	int			y;
	int			size;
	int			nmb_ghost;
	int			*ghost_x;
	int			*ghost_y;
	int			move;
	int			is_anime;
}t_maps;

void	left(t_maps *map);
void	high(t_maps *map);
int32_t	death(t_maps *map);
void	right(t_maps *map);
void	botom(t_maps *map);
void	ft_error_mlx(void);
void	ft_verif_ber(char *src);
void	ft_free_map(char **map);
void	destroy_img(t_maps *map);
void	verif_c(t_maps *parsing);
void	display_obj(t_maps *map);
void	ft_ghost_move(void *param);
void	display_ghost(t_maps *map);
void	verif_len(t_maps *parsing);
void	final_map(t_maps *parsing);
void	display_number(t_maps *map);
void	destroy_number(t_maps *map);
void	verif_char(t_maps *parsing);
void	destroy_texture(t_maps *map);
void	verif_quote(t_maps *parsing);
void	init_texture(t_texture *load);
void	display_last_line(t_maps *map);
int32_t	so_long(t_maps *map, int size);
void	ft_is_finished(t_maps *parsing);
int32_t	victory(mlx_t mlx, t_maps *map);
void	init_texture_32(t_texture *load);
int		init_map(t_maps *parsing, int len);
void	display_mouv(t_maps *map, int mouv);
void	ft_error(t_maps *parsing, char *error);
char	*ft_malloc_line(t_maps *parsing, int i);
void	save_ghost(t_maps *parsing, int x, int y);
char	choice_char(t_maps *parsing, int i, size_t j);
void	display_a_l(char c, t_maps *map, int *i, int size);
void	display_o_3(char c, t_maps *map, int *i, int size);
void	init_image(t_image *load, t_texture *loaded, int size);
void	init_number(t_image *image, t_texture *texture, int secu);
int		loop_verif_char(char *src, const char c, t_maps *parsing, int i);

#endif