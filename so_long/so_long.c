/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:39:41 by trebours          #+#    #+#             */
/*   Updated: 2024/01/25 15:46:58 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_verif_ber(char *src);
{
	(void)src;
	//utiliser strchr de la libft + message d'erreur
}

int	main(int argc, char *argv)
{
	if (argc != 2)
	{
		ft_printf("Error\nBad imput\n");
		exit(1);
	}
	ft_verif_ber(argv[1]);
}