/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:35:55 by trebours          #+#    #+#             */
/*   Updated: 2024/01/30 15:08:37 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	ft_corner_high(t_maps *parsing, int i, size_t j, char c)
{
	if (j < parsing->len_line_map - 2 && i < parsing->len_map - 1
		&& parsing->map[i][j] == c && parsing->map[i][j + 1] == c
		&& parsing->map[i + 1][j] == c)
	{
		if ((j == 0 && i == 0) || (j > 0 && parsing->map[i][j - 1] != c
			&& i == 0) || (j > 0 && parsing->map[i][j - 1] != c && i > 0
			&& parsing->map[i - 1][j] != c) || (j == 0 && i > 0
			&& parsing->map[i - 1][j] != c))
			return ('o');
	}
	else if (j > 0 && i < parsing->len_map - 1
		&& parsing->map[i][j] == c && parsing->map[i][j - 1] == c
		&& parsing->map[i + 1][j] == c)
	{
		if ((j == parsing->len_line_map - 2 && i == 0) || (j
				< parsing->len_line_map - 2 && parsing->map[i][j + 1] != c
			&& i == 0) || (j < parsing->len_line_map - 2
			&& parsing->map[i][j + 1] != c && i > 0
			&& parsing->map[i - 1][j] != c) || (j == parsing->len_line_map - 2
			&& i > 0 && parsing->map[i - 1][j] != c))
			return ('p');
	}
	return (c);
}

static char	ft_corner_botom(t_maps *parsing, int i, size_t j, char c)
{
	if (j < parsing->len_line_map - 2 && i > 0 && parsing->map[i][j] == c
		&& parsing->map[i][j + 1] == c && parsing->map[i - 1][j] == c)
	{
		if ((j == 0 && i == parsing->len_map - 1) || (j > 0
				&& parsing->map[i][j - 1] != c && i == parsing->len_map - 1)
			|| (j && parsing->map[i][j - 1] != c && i < parsing->len_map - 1
			&& parsing->map[i + 1][j] != c) || (j == 0 && i < parsing->len_map
			- 1 && parsing->map[i + 1][j] != c))
			return ('m');
	}
	else if (j > 0 && i > 0 && parsing->map[i][j] == c
		&& parsing->map[i][j - 1] == c && parsing->map[i - 1][j] == c)
	{
		if ((j == parsing->len_line_map - 2 && i == parsing->len_map - 1)
			|| (j < parsing->len_line_map - 2 && parsing->map[i][j + 1] != c
			&& i == parsing->len_map - 1) || (j < parsing->len_line_map - 2
			&& parsing->map[i][j + 1] != c && i < parsing->len_map - 1
			&& parsing->map[i + 1][j] != c) || (j == parsing->len_line_map - 2
			&& i < parsing->len_map - 1
			&& parsing->map[i + 1][j] != c))
			return ('n');
	}
	return (c);
}

static char	ft_line(t_maps *parsing, int i, size_t j, char c)
{
	if (parsing->map[i][j] == c && (j < parsing->len_line_map - 2
		&& parsing->map[i][j + 1] != c) && (j > 0
		&& parsing->map[i][j - 1] != c) && (i < parsing->len_map - 1
		&& parsing->map[i + 1][j] != c) && (i > 0
		&& parsing->map[i - 1][j] != c))
		return ('c');
	if (parsing->map[i][j] == c && (i > 0 && parsing->map[i - 1][j] == c)
		&& (i < parsing->len_map - 1 && parsing->map[i + 1][j] != c))
		return ('i');
	if (parsing->map[i][j] == c && (i > 0 && parsing->map[i - 1][j] != c)
		&& (i < parsing->len_map - 1 && parsing->map[i + 1][j] == c))
		return ('j');
	if (parsing->map[i][j] == c && (j > 0 && parsing->map[i][j - 1] == c)
		&& (j < parsing->len_line_map - 2 && parsing->map[i][j + 1] != c))
		return ('k');
	if (parsing->map[i][j] == c && (j > 0 && parsing->map[i][j - 1] != c)
		&& (j < parsing->len_line_map - 2 && parsing->map[i][j + 1] == c))
		return ('l');
	if (parsing->map[i][j] == c && ((j > parsing->len_line_map - 2
		&& parsing->map[i][j + 1] == c) || (j > 0 && parsing->map[i][j - 1]
		== c)))
		return ('b');
	return ('a');
}

static char	ft_t(t_maps *parsing, int i, size_t j, char c)
{
	if (parsing->map[i][j] == c && (j > 0 && parsing->map[i][j - 1] == c)
	&& (j < parsing->len_line_map - 2 && parsing->map[i][j + 1] == c)
	&& (i > 0 && parsing->map[i - 1][j] == c))
	{
		if ((i == parsing->len_map - 1) || (i < parsing->len_map - 1
				&& parsing->map[i + 1][j] != c))
			return ('f');
		else
			return ('d');
	}
	if (parsing->map[i][j] == c && (j > 0 && parsing->map[i][j - 1] == c)
		&& (j < parsing->len_line_map - 2 && parsing->map[i][j + 1] == c)
		&& (i < parsing->len_map - 1 && parsing->map[i + 1][j] == c))
		return ('e');
	if (parsing->map[i][j] == c && (j < parsing->len_line_map - 2
		&& parsing->map[i][j + 1] == c) && (i > 0 && parsing->map[i - 1][j]
		== c) && (i < parsing->len_map - 1 && parsing->map[i + 1][j] == c))
		return ('h');
	if (parsing->map[i][j] == c && (j > 0 && parsing->map[i][j - 1] == c)
		&& (i > 0 && parsing->map[i - 1][j] == c) && (i < parsing->len_map - 1
		&& parsing->map[i + 1][j] == c))
		return ('g');
	return (c);
}

char	choice_char(t_maps *parsing, int i, size_t j)
{
	char		rsl;
	const char	c = '1';

	rsl = ft_corner_high(parsing, i, j, c);
	if (rsl == c)
		rsl = ft_corner_botom(parsing, i, j, c);
	if (rsl == c)
		rsl = ft_t(parsing, i, j, c);
	if (rsl == c)
		rsl = ft_line(parsing, i, j, c);
	return (rsl);
}
