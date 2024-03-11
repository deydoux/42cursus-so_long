/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:26:52 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/11 15:44:41 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	open_tiles_img(void *mlx, t_img img[2])
{
	img[0] = open_img(mlx, "assets/empty.xpm", IMAGE_SIZE, IMAGE_SIZE);
	if (!img[0].ptr)
	{
		ft_dprintf(STDERR_FILENO, ERR_OPEN_IMG, "assets/empty.xpm");
		return (true);
	}
	img[1] = open_img(mlx, "assets/wall.xpm", IMAGE_SIZE, IMAGE_SIZE);
	if (!img[1].ptr)
	{
		ft_dprintf(STDERR_FILENO, ERR_OPEN_IMG, "assets/wall.xpm");
		mlx_destroy_image(mlx, img[0].ptr);
		return (true);
	}
	return (false);
}

static bool	put_tiles(void *mlx, t_map map)
{
	t_img	img[2];
	size_t	x;
	size_t	y;

	if (open_tiles_img(mlx, img))
		return (true);
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
			put_img_to_img(img[*map.str == '1'], map.img, x, y);
			x += IMAGE_SIZE;
		}
		map.str++;
	}
	mlx_destroy_image(mlx, img[0].ptr);
	mlx_destroy_image(mlx, img[1].ptr);
	return (false);
}

bool	create_map_img(void *mlx, t_map *map)
{
	if (map->heigh > INT_MAX / IMAGE_SIZE || map->width > INT_MAX / IMAGE_SIZE)
	{
		ft_putstr_fd(ERR_MAP_SIZE, STDERR_FILENO);
		return (true);
	}
	map->img = new_img(mlx, map->heigh * IMAGE_SIZE, map->width * IMAGE_SIZE);
	if (!map->img.ptr)
	{
		ft_putstr_fd(ERR_MAP_IMG, STDERR_FILENO);
		return (true);
	}
	return (put_tiles(mlx, *map));
}
