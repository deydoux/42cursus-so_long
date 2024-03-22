/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:26:52 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/22 13:33:45 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

static t_img	get_tile(char c, t_spr spr)
{
	if (c == '1')
		return (spr.tiles[1]);
	if (c == 'E')
		return (spr.e);
	return (spr.tiles[0]);
}

static bool	copy_tiles(t_spr spr, t_map map)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (*map.str)
	{
		if (*map.str == '\n')
		{
			x = 0;
			y += IMAGE_SIZE;
		}
		else
		{
			copy_img(get_tile(*map.str, spr), map.img, x, y);
			x += IMAGE_SIZE;
		}
		map.str++;
	}
	return (false);
}

static void	free_tiles(void *mlx, t_spr *spr)
{
	mlx_destroy_image(mlx, spr->e.ptr);
	spr->e.ptr = NULL;
	mlx_destroy_image(mlx, spr->tiles[1].ptr);
	spr->tiles[1].ptr = NULL;
}

bool	init_map_img(void *mlx, t_spr *spr, t_map *map)
{
	map->img = new_img(mlx, map->heigh * IMAGE_SIZE, map->width * IMAGE_SIZE);
	if (!map->img.ptr)
	{
		ft_dprintf(STDERR_FILENO, ERR_NEW, "map image");
		return (true);
	}
	if (copy_tiles(*spr, *map))
		return (true);
	free_tiles(mlx, spr);
	return (false);
}
