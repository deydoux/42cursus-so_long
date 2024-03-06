/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:26:52 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/05 14:18:17 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	open_tiles_img(void *mlx, char *map_str, t_img img[2])
{
	img[0] = open_img(mlx, "assets/empty.xpm", IMAGE_SIZE, IMAGE_SIZE);
	if (!img[0].ptr)
	{
		ft_putstr_fd("Error\nFailed to open assets/empty.xpm\n", STDERR_FILENO);
		free_mlx(mlx);
		free(map_str);
		exit(EXIT_FAILURE);
	}
	img[1] = open_img(mlx, "assets/wall.xpm", IMAGE_SIZE, IMAGE_SIZE);
	if (!map_str)
	{
		ft_putstr_fd("Error\nFailed to open assets/wall.xpm\n", STDERR_FILENO);
		mlx_destroy_image(mlx, img[0].ptr);
		free_mlx(mlx);
		free(map_str);
		exit(EXIT_FAILURE);
	}
}

static void	put_tiles(void *mlx, t_map map)
{
	t_img	img[2];
	size_t	x;
	size_t	y;

	open_tiles_img(mlx, map.str, img);
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
}

void	create_map_img(void *mlx, t_map *map)
{
	if (map->heigh > INT_MAX / IMAGE_SIZE || map->width > INT_MAX / IMAGE_SIZE)
	{
		ft_putstr_fd("Error\nMap too large\n", STDERR_FILENO);
		free_mlx(mlx);
		free(map->str);
		exit(EXIT_FAILURE);
	}
	map->img = new_img(mlx, map->heigh * IMAGE_SIZE, map->width * IMAGE_SIZE);
	if (!map->img.ptr)
	{
		ft_putstr_fd("Error\nFailed to create map image\n", STDERR_FILENO);
		free_mlx(mlx);
		free(map->str);
		exit(EXIT_FAILURE);
	}
	put_tiles(mlx, *map);
}
