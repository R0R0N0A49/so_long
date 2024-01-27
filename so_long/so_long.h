/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:17:33 by trebours          #+#    #+#             */
/*   Updated: 2024/01/27 14:15:22 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

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

void	ft_verif_ber(char *src);
void	ft_free_map(char **map);
void	verif_C(t_maps *parsing);
void	verif_len(t_maps *parsing);
void	verif_char(t_maps *parsing);
void	verif_quote(t_maps *parsing);
void	ft_is_finished(t_maps *parsing);
void	init_map(t_maps *parsing, int len);
void	ft_error(t_maps *parsing, char *error);
int		loop_verif_char(char *src, const char c, t_maps *parsing, int i);

#endif