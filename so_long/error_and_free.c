/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:43:29 by trebours          #+#    #+#             */
/*   Updated: 2024/02/15 16:51:18 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_mlx(void)
{
	ft_printf("%s", (mlx_strerror(mlx_errno)));
	exit(EXIT_FAILURE);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_error(t_maps *parsing, char *error)
{
	ft_printf("Error\n%s\n", error);
	if (parsing && parsing->map)
		ft_free_map(parsing->map);
	exit(1);
}
