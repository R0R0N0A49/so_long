/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:17:33 by trebours          #+#    #+#             */
/*   Updated: 2024/01/27 11:18:42 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_maps
{
	char	*file_maps;
	int		len_map;
	char	**map;
	size_t	len_ligne_map;
}t_maps;

void	ft_verif_ber(char *src);
void	verif_C(t_maps *parsing);
void	init_map(t_maps *parsing);
void	verif_len(t_maps *parsing);
void	verif_char(t_maps *parsing);
void	verif_quote(t_maps *parsing);
void	ft_error(t_maps *parsing, char *error);
int		loop_verif_char(char *src, const char c, t_maps *parsing);

#endif