/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:27:32 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/12 10:41:54 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"

bool	parse_map(char *filename, t_map *map)
{
	if (read_map(filename, map))
		return (true);
	if (check_map_components(*map, filename)
		|| check_closed_map(*map, filename)
		|| check_valid_path(*map, filename))
	{
		free(map->str);
		return (true);
	}
	return (false);
}
