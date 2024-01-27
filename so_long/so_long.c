/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:39:41 by trebours          #+#    #+#             */
/*   Updated: 2024/01/27 10:03:36 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void ft_error_wall(t_maps *parsing, char *error)
{
	ft_printf("Error\n%s\n", error);
	ft_free_map(parsing->map);
	exit(1);
}

void	verif_len(t_maps *parsing)
{
	int	i;

	i = 0;
	parsing->len_ligne_map = ft_strlen(parsing->map[i]);
	while (i < parsing->len_map)
	{
		if (ft_strlen(parsing->map[i]) != parsing->len_ligne_map)
			ft_error_wall(parsing, "Map incomplete");
		i++;
	}
	if (parsing->len_ligne_map < 4 || parsing->len_map < 3)
		ft_error_wall(parsing, "Map incomplete");
}

void	verif_quote(t_maps *parsing)
{
	int	i;
	unsigned int	j;

	i = 0;
	while( i < parsing->len_map)
	{
		if (i == 0 || i == parsing->len_map - 1)
		{
			j = 0;
			while (j < parsing->len_ligne_map - 2)
			{
				if (parsing->map[i][j] != '1')
					ft_error_wall(parsing, "Wall incomplete");
				j++;
			}
		}
		else if (parsing->map[i][0] != '1'
			|| parsing->map[i][parsing->len_ligne_map - 2] != '1')
			ft_error_wall(parsing, "Wall incomplete");
		i++;
	}
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
	init_maps(&parsing);
	verif_len(&parsing);
	verif_quote(&parsing);
	ft_free_map(parsing.map);
	return (0);
}
