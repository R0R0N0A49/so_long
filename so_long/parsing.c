/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:18:57 by trebours          #+#    #+#             */
/*   Updated: 2024/01/27 15:56:03 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verif_len(t_maps *parsing)
{
	int	i;

	i = 0;
	parsing->len_line_map = ft_strlen(parsing->map[i]);
	while (i < parsing->len_map)
	{
		if (ft_strlen(parsing->map[i]) != parsing->len_line_map)
			ft_error(parsing, "Map incomplete");
		i++;
	}
	if (parsing->len_line_map < 4 || parsing->len_map < 3)
		ft_error(parsing, "Map incomplete, you need more line or column");
}

void	verif_quote(t_maps *parsing)
{
	int				i;
	unsigned int	j;

	i = 0;
	while (i < parsing->len_map)
	{
		if (i == 0 || i == parsing->len_map - 1)
		{
			j = 0;
			while (j < parsing->len_line_map - 1)
			{
				if (parsing->map[i][j] != '1')
					ft_error(parsing, "Wall incomplete");
				j++;
			}
		}
		else if (parsing->map[i][0] != '1'
			|| parsing->map[i][parsing->len_line_map - 2] != '1')
			ft_error(parsing, "Wall incomplete");
		i++;
	}
}

void	ft_verif_ber(char *src)
{
	int	len_src;
	int	i;

	len_src = ft_strlen(src);
	i = 0;
	if (src[len_src - 1] != 'r')
		i++;
	if (src[len_src - 2] != 'e')
		i++;
	if (src[len_src - 3] != 'b')
		i++;
	if (src[len_src - 4] != '.')
		i++;
	if (i > 0)
	{
		ft_printf("Error\nthe file has the wrong format\n");
		exit(1);
	}
}

int	loop_verif_char(char *src, const char c, t_maps *parsing, int i)
{
	size_t	j;
	int		tmp;

	j = 1;
	tmp = 0;
	while (src[j] != '\n')
	{
		if (src[j] == c)
			tmp++;
		if (src[j] == 'P')
		{
			parsing->x = i;
			parsing->y = j;
		}
		if (src[j] != 'C' && src[j] != 'E' && src[j] != 'P' && src[j] != '0'
			&& src[j] != '1')
			ft_error(parsing, "Char unknown");
		j++;
	}
	return (tmp);
}

void	verif_char(t_maps *parsing)
{
	const char	str[3] = "EP\0";
	int			tmp;
	int			i;
	int			k;

	k = 0;
	while (str[k])
	{
		i = 0;
		tmp = 0;
		while (parsing->map[i])
		{
			tmp += loop_verif_char(parsing->map[i], str[k], parsing, i);
			i++;
		}
		if (tmp > 1)
			ft_error(parsing, "too many Players or Exits");
		if (tmp == 0)
			ft_error(parsing, "there is no Player or Exit");
		k++;
	}
	verif_c(parsing);
}
