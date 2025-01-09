/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:26:52 by deydoux           #+#    #+#             */
/*   Updated: 2025/01/09 16:53:59 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

static t_img	get_tile(t_map map, size_t x, size_t y, t_spr spr)
{
	if (map.str[x + y * map.width] == '1')
		return (get_tile_1(map, x, y, spr.i1));
	if (map.str[x + y * map.width] == 'R')
		return (spr.r);
	if (map.str[x + y * map.width] == 'E')
		return (spr.e);
	return (spr.i0);
}

static bool	copy_tiles(t_spr spr, t_map map)
{
	size_t	x;
	size_t	y;
	char	*str;

	x = 0;
	y = 0;
	str = map.str;
	while (*str)
	{
		if (*str == '\n')
		{
			x = 0;
			y++;
		}
		else
		{
			copy_img(get_tile(map, x, y, spr), map.img, x * IMAGE_SIZE,
				y * IMAGE_SIZE);
			x++;
		}
		str++;
	}
	return (false);
}

static void	free_tiles(void *mlx, t_spr *spr)
{
	mlx_destroy_image(mlx, spr->e.ptr);
	spr->e.ptr = NULL;
	free_spr_1(mlx, &spr->i1);
}

bool	init_map_img(void *mlx, t_spr *spr, t_map *map)
{
	map->img = new_img(mlx, map->heigh * IMAGE_SIZE,
			(map->width - 1) * IMAGE_SIZE);
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
