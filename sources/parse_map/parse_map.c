/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:27:32 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/17 22:55:16 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"

static bool	check_map_size(t_map map, char *filename)
{
	if (map.heigh > MAX_IMG_DIMENSION / IMAGE_SIZE
		|| map.width > MAX_IMG_DIMENSION / IMAGE_SIZE
		|| map.heigh * map.width > MAX_IMG_PIXEL / IMAGE_SIZE)
	{
		ft_dprintf(STDERR_FILENO, ERR_MAP_SIZE, filename, IMAGE_SIZE);
		return (true);
	}
	return (false);
}

bool	parse_map(char *filename, t_map *map)
{
	return (read_map(filename, map)
		|| check_map_size(*map, filename)
		|| check_map_components(*map, filename)
		|| check_closed_map(*map, filename)
		|| check_valid_path(*map, filename));
}
