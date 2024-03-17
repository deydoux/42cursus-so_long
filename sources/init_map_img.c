/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:26:52 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/17 23:09:26 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_img	get_tile(char c, t_sprites sprites)
{
	if (c == '0' || c == 'P')
		return (sprites.empty);
	if (c == '1')
		return (sprites.wall);
	if (c == 'C')
		return (sprites.collectible);
	if (c == 'E')
		return (sprites.exit);
	return (sprites.empty);
}

static bool	copy_tiles(t_sprites sprites, t_map map)
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
			copy_img(get_tile(*map.str, sprites), map.img, x, y);
			x += IMAGE_SIZE;
		}
		map.str++;
	}
	return (false);
}

static void	free_tiles(void *mlx, t_sprites *sprites)
{
	mlx_destroy_image(mlx, sprites->collectible.ptr);
	sprites->collectible.ptr = NULL;
	mlx_destroy_image(mlx, sprites->exit.ptr);
	sprites->exit.ptr = NULL;
	mlx_destroy_image(mlx, sprites->wall.ptr);
	sprites->wall.ptr = NULL;
}

bool	init_map_img(void *mlx, t_sprites *sprites, t_map *map)
{
	map->img = new_img(mlx, map->heigh * IMAGE_SIZE, map->width * IMAGE_SIZE);
	if (!map->img.ptr)
	{
		ft_putstr_fd(ERR_MAP_IMG, STDERR_FILENO);
		return (true);
	}
	if (copy_tiles(*sprites, *map))
		return (true);
	free_tiles(mlx, sprites);
	return (false);
}
