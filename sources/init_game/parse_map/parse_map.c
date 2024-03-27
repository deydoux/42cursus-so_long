/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:27:32 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/27 17:13:29 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"

static bool	check_map_size(t_map map)
{
	if (map.heigh > MAX_IMG_DIMENSION / IMAGE_SIZE
		|| (map.width - 1) > MAX_IMG_DIMENSION / IMAGE_SIZE
		|| map.heigh * (map.width - 1) > MAX_IMG_PIXEL / IMAGE_SIZE)
	{
		ft_dprintf(STDERR_FILENO, ERR_MAP_SIZE, IMAGE_SIZE);
		return (true);
	}
	return (false);
}

static bool	check_characters(t_map map, char *filename)
{
	size_t	i;

	i = 0;
	while (map.str[i])
	{
		if (!ft_strchr(MAP_CHARSET, map.str[i]))
		{
			ft_dprintf(STDERR_FILENO, ERR_UEXP_CHAR, map.str[i], filename,
				i / map.width + 1, i % map.width + 1);
			return (true);
		}
		i++;
	}
	return (false);
}

bool	parse_map(char *filename, t_map *map)
{
	return (read_map(filename, map)
		|| check_map_size(*map)
		|| check_characters(*map, filename)
		|| check_map_components(*map, filename)
		|| check_closed_map(*map, filename)
		|| check_valid_path(*map, filename)
		|| find_collects(map, filename));
}
