/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:23:54 by trebours          #+#    #+#             */
/*   Updated: 2024/02/16 09:47:29 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_maps	parsing;

	if (argc != 2)
		ft_error(NULL, "you must input a map");
	ft_verif_ber(argv[1]);
	parsing.file_maps = argv[1];
	parsing.nmb_ghost = 0;
	parsing.ghost_x = NULL;
	parsing.ghost_y = NULL;
	if (init_map(&parsing, 0))
		ft_error(&parsing, "Error map");
	verif_len(&parsing);
	verif_quote(&parsing);
	verif_char(&parsing);
	ft_is_finished(&parsing);
	final_map(&parsing);
	srand(time(NULL));
	parsing.finish = 1;
	if (parsing.len_line_map - 2 > 30 || parsing.len_map > 14)
		so_long(&parsing, 32);
	else
		so_long(&parsing, 64);
	ft_free_map(parsing.map);
	return (0);
}
