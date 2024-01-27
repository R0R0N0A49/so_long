/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:39:41 by trebours          #+#    #+#             */
/*   Updated: 2024/01/27 15:11:43 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_error(t_maps *parsing, char *error)
{
	ft_printf("Error\n%s\n", error);
	ft_free_map(parsing->map);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_maps	parsing;

	if (argc != 2)
	{
		ft_printf("Error\nBad imput\n");
		exit(1);
	}
	ft_verif_ber(argv[1]);
	parsing.file_maps = argv[1];
	init_map(&parsing, 0);
	verif_len(&parsing);
	verif_quote(&parsing);
	verif_char(&parsing);
	ft_is_finished(&parsing);
	ft_free_map(parsing.map);
	return (0);
}
