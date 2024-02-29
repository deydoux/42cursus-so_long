/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:26:52 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/29 13:29:45 by deydoux          ###   ########.fr       */
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

	open_tiles_img(mlx, map.str, img);
	put_img_to_img(img[0], map.img, 0, 0);
	put_img_to_img(img[1], map.img, 32, 32);
	mlx_destroy_image(mlx, img[0].ptr);
	mlx_destroy_image(mlx, img[1].ptr);
}

void	create_map_img(void *mlx, t_map *map)
{
	map->width *= IMAGE_SIZE;
	map->heigh *= IMAGE_SIZE;
	if (map->heigh > INT_MAX || map->width > INT_MAX)
	{
		ft_putstr_fd("Error\nMap too large\n", STDERR_FILENO);
		free_mlx(mlx);
		free(map->str);
		exit(EXIT_FAILURE);
	}
	map->img = new_img(mlx, (int)map->width, (int)map->heigh);
	if (!map->img.ptr)
	{
		ft_putstr_fd("Error\nFailed to create map image\n", STDERR_FILENO);
		free_mlx(mlx);
		free(map->str);
		exit(EXIT_FAILURE);
	}
	put_tiles(mlx, *map);
}
