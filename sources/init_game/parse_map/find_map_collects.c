/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map_collects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:52:06 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/28 12:59:55 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"

static bool	new_collect(size_t i, t_map *map)
{
	t_collect	*collect;
	t_list		*new;

	collect = malloc(sizeof(*collect));
	if (!collect)
		return (true);
	new = ft_lstnew(collect);
	if (!new)
	{
		free(collect);
		return (true);
	}
	collect->active = true;
	collect->pos.x = i % map->width * IMAGE_SIZE;
	collect->pos.y = i / map->width * IMAGE_SIZE;
	ft_lstadd_back(&map->collects, new);
	return (false);
}

bool	find_map_collects(t_map *map, char *filename)
{
	size_t	i;

	i = 0;
	while (map->str[i])
	{
		if (map->str[i] == 'C')
		{
			if (new_collect(i, map))
			{
				ft_putstr_fd(ERR_COL_POS, STDERR_FILENO);
				return (true);
			}
		}
		i++;
	}
	if (!map->collects)
	{
		ft_dprintf(STDERR_FILENO, ERR_NO_CMPN, "collectible", filename);
		return (true);
	}
	return (false);
}
