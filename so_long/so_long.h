/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:17:33 by trebours          #+#    #+#             */
/*   Updated: 2024/01/27 08:56:35 by trebours         ###   ########.fr       */
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
void	init_maps(t_maps *parsing);

#endif