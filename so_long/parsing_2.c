/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:56:35 by trebours          #+#    #+#             */
/*   Updated: 2024/01/27 11:19:30 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verif_C(t_maps *parsing)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (parsing->map[i])
	{
		tmp += loop_verif_char(parsing->map[i], 'C', parsing);
		i++;
	}
	if (tmp == 0)
		ft_error(parsing, "there are not object");
}