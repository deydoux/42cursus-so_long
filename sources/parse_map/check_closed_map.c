/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:58:05 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/18 00:18:06 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"

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
		ft_dprintf(STDERR_FILENO, ERR_CLOSE_MAP, filename,
			i / (map.width + 1) + 1, i % (map.width + 1) + 1);
		return (true);
	}
	return (false);
}
