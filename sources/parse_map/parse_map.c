/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:27:32 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/11 14:36:43 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"

void	parse_map(char *filename, t_map *map)
{
	if (read_map(filename, map))
		exit(EXIT_FAILURE);
	if (check_map_components(*map, filename)
		|| check_closed_map(*map, filename)
		|| check_valid_path(*map, filename))
	{
		free(map->str);
		exit(EXIT_FAILURE);
	}
}
