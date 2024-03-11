/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:58:05 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/11 14:41:26 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"

static void	throw_close_map(size_t i, size_t map_width, char *filename)
{
	size_t	len;

	len = map_width + 1;
	ft_dprintf(STDERR_FILENO, ERR_CLOSE_MAP, filename,
		i / len + 1, i % len + 1);
}

static bool	check_top_walls(size_t *i, char *map_str)
{
	while (map_str[*i] == '1')
		(*i)++;
	return (map_str[*i] != '\n');
}

static bool	check_bottom_walls(size_t *i, char *map_str)
{
	while (map_str[--*i] == '1')
		continue ;
	return (map_str[*i] != '\n');
}

static bool	check_vertical_walls(size_t *i, char *map_str)
{
	while (map_str[*i])
	{
		if (map_str[*i] == '\n')
		{
			if (!map_str[*i + 1])
				return (check_bottom_walls(i, map_str));
			if (map_str[*i - 1] != '1')
			{
				(*i)--;
				return (true);
			}
			if (map_str[*i + 1] != '1')
			{
				(*i)++;
				return (true);
			}
		}
		(*i)++;
	}
	return (false);
}

bool	check_closed_map(t_map map, char *filename)
{
	size_t	i;

	i = 0;
	if (check_top_walls(&i, map.str) || check_vertical_walls(&i, map.str))
	{
		throw_close_map(i, map.width, filename);
		return (true);
	}
	return (false);
}
