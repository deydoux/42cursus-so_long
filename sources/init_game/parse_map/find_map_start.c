/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:36:36 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/28 12:59:40 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"

bool	find_map_start(t_map *map, char *filename)
{
	size_t	i;

	i = 0;
	while (map->str[i] != 'P' && map->str[i])
		i++;
	if (!map->str[i])
	{
		ft_dprintf(STDERR_FILENO, ERR_NO_CMPN, "start position", filename);
		return (true);
	}
	map->start.x = i % map->width * IMAGE_SIZE;
	map->start.y = i / map->width * IMAGE_SIZE;
	while (map->str[++i])
	{
		if (map->str[i] == 'P')
		{
			ft_dprintf(STDERR_FILENO, ERR_DUP_CMPN, "start position", filename,
				i / map->width + 1, i % map->width + 1);
			return (true);
		}
	}
	return (false);
}
