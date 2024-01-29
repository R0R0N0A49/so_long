/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:17:33 by trebours          #+#    #+#             */
/*   Updated: 2024/01/29 11:04:05 by trebours         ###   ########.fr       */
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

typedef struct s_wall
{
	mlx_image_t	*wall_a; //wall_vertical.png
	mlx_image_t	*wall_b; //wall_horizontal.png
	mlx_image_t	*wall_c; //wall_alone.png
	mlx_image_t	*wall_d; //cross_wall.png
	mlx_image_t	*wall_e; //t_botom.png
	mlx_image_t	*wall_f; //t_high.png
	mlx_image_t	*wall_g; //t_left.png
	mlx_image_t	*wall_h; //t_right.png
	mlx_image_t	*wall_i; //end_wall_botom.png
	mlx_image_t	*wall_j; //end_wall_high.png
	mlx_image_t	*wall_k; //end_wall_left.png
	mlx_image_t	*wall_l; //end_wall_right.png
	mlx_image_t	*wall_m; //corner_botom_left.png
	mlx_image_t	*wall_n; //corner_botom_right.png
	mlx_image_t	*wall_o; //corner_high_left.png
	mlx_image_t	*wall_p; //corner_high_right.png
}t_wall;

void	ft_verif_ber(char *src);
void	ft_free_map(char **map);
void	verif_c(t_maps *parsing);
void	verif_len(t_maps *parsing);
void	verif_char(t_maps *parsing);
void	verif_quote(t_maps *parsing);
void	ft_is_finished(t_maps *parsing);
void	init_map(t_maps *parsing, int len);
void	ft_error(t_maps *parsing, char *error);
int		loop_verif_char(char *src, const char c, t_maps *parsing, int i);

#endif