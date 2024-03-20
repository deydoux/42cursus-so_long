/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:27:32 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/19 14:04:55 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"

static bool	check_map_size(t_map map, char *filename)
{
	if (map.size.y > MAX_IMG_DIMENSION / IMAGE_SIZE
		|| map.size.x > MAX_IMG_DIMENSION / IMAGE_SIZE
		|| map.size.y * map.size.x > MAX_IMG_PIXEL / IMAGE_SIZE)
	{
		ft_dprintf(STDERR_FILENO, ERR_MAP_SIZE, filename, IMAGE_SIZE);
		return (true);
	}
	return (false);
}

static bool	check_characters(t_map map, char *filename)
{
	size_t	len;
	size_t	i;

	len = map.size.x + 1;
	i = 0;
	while (map.str[i])
	{
		if (!ft_strchr("01CEP\n", map.str[i]))
		{
			ft_dprintf(STDERR_FILENO, ERR_UEXP_CHAR, map.str[i], filename,
				i / len + 1, i % len + 1);
			return (true);
		}
		i++;
	}
	return (false);
}

bool	parse_map(char *filename, t_map *map)
{
	return (read_map(filename, map)
		|| check_map_size(*map, filename)
		|| check_characters(*map, filename)
		|| check_map_components(*map, filename)
		|| check_closed_map(*map, filename)
		|| check_valid_path(*map, filename)
		|| find_collectibles(map, filename));
}
