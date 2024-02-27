/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 22:58:09 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/27 07:45:12 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	propagate_path(t_map *map, size_t position)
{
	if (ft_strchr(".1cep", map->str[position]))
		return ;
	if (map->str[position] == '0')
		map->str[position] = '.';
	else
		map->str[position] = ft_tolower(map->str[position]);
	propagate_path(map, position + 1);
	propagate_path(map, position - 1);
	propagate_path(map, position + 1 + map->width);
	propagate_path(map, position - 1 - map->width);
}

static void	revert_propagation(char *str)
{
	while (*str)
	{
		if (*str == '.')
			*str = '0';
		else
			*str = ft_toupper(*str);
		str++;
	}
}

void	valid_path(t_map *map)
{
	propagate_path(map, ft_strchr(map->str, 'P') - map->str);
	if (ft_strchr(map->str, 'C') || ft_strchr(map->str, 'E'))
	{
		free(map->str);
		ft_putstr_fd("Error\nNo valid path found\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	revert_propagation(map->str);
}
