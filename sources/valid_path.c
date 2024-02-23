/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 22:58:09 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/23 20:26:10 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	propagate_path(t_map *map, size_t position)
{
	if (ft_strchr(".1cep", map->ptr[position]))
		return ;
	if (map->ptr[position] == '0')
		map->ptr[position] = '.';
	else
		map->ptr[position] = ft_tolower(map->ptr[position]);
	propagate_path(map, position + 1);
	propagate_path(map, position - 1);
	propagate_path(map, position + 1 + map->width);
	propagate_path(map, position - 1 - map->width);
}

void	valid_path(t_map *map)
{
	propagate_path(map, ft_strchr(map->ptr, 'P') - map->ptr);
	if (ft_strchr(map->ptr, 'C') || ft_strchr(map->ptr, 'E'))
	{
		free(map->ptr);
		ft_putstr_fd("Error\nNo valid path found\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
