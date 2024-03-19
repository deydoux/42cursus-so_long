/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_collectibles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:52:06 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/19 13:51:12 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"

static bool	new_collectible(size_t i, t_map *map)
{
	t_dim	*collectible;
	t_list		*new;

	collectible = malloc(sizeof(*collectible));
	if (!collectible)
		return (true);
	new = ft_lstnew(collectible);
	if (!new)
	{
		free(collectible);
		return (true);
	}
	collectible->x = i / (map->width + 1) * IMAGE_SIZE;
	collectible->y = i % (map->width + 1) * IMAGE_SIZE;
	ft_lstadd_back(&map->collectibles, new);
	return (false);
}

bool	find_collectibles(t_map *map, char *filename)
{
	size_t	i;

	i = 0;
	while (map->str[i])
	{
		if (map->str[i] == 'C')
		{
			if (new_collectible(i, map))
			{
				ft_putstr_fd(ERR_COL_POS, STDERR_FILENO);
				return (true);
			}
		}
		i++;
	}
	if (!map->collectibles)
	{
		ft_dprintf(STDERR_FILENO, ERR_NO_CMPN, "collectible", filename);
		return (true);
	}
	return (false);
}
