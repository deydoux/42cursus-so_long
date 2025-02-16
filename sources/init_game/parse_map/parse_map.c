/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:27:32 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/28 13:03:26 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"

bool	parse_map(char *filename, t_map *map)
{
	return (read_map_file(filename, map)
		|| check_map_size(*map)
		|| check_map_charset(*map, filename)
		|| check_map_exit(*map, filename)
		|| find_map_start(map, filename)
		|| find_map_collects(map, filename)
		|| check_map_walls(*map, filename)
		|| check_map_path(*map, filename));
}
