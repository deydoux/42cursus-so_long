/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:26:52 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/28 17:53:36 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	open_tiles_img(void *mlx, char *map_str, t_img img[2])
{
	int	size;

	size = IMAGE_SIZE;
	img[0].ptr = mlx_xpm_file_to_image(mlx, "assets/empty.xpm", &size, &size);
	if (!img[0].ptr)
	{
		ft_putstr_fd("Error\nFailed to open assets/empty.xpm\n", STDERR_FILENO);
		free_mlx(mlx);
		free(map_str);
		exit(EXIT_FAILURE);
	}
	img[1].ptr = mlx_xpm_file_to_image(mlx, "assets/wall.xpm", &size, &size);
	if (!map_str)
	{
		ft_putstr_fd("Error\nFailed to open assets/wall.xpm\n", STDERR_FILENO);
		mlx_destroy_image(mlx, img[0].ptr);
		free_mlx(mlx);
		free(map_str);
		exit(EXIT_FAILURE);
	}
	get_img(&img[0]);
	get_img(&img[1]);
}

static void	put_tiles(void *mlx, t_map map)
{
	t_img	img[2];

	open_tiles_img(mlx, map.str, img);
	put_img_to_map(img[0], map.img, 0, 0);
	put_img_to_map(img[1], map.img, 32, 0);
	mlx_destroy_image(mlx, img[0].ptr);
	mlx_destroy_image(mlx, img[1].ptr);
}

void	create_map_img(void *mlx, t_map *map)
{
	map->width *= IMAGE_SIZE;
	if (map->width < WINDOW_WIDTH)
		map->width = WINDOW_WIDTH;
	map->heigh *= IMAGE_SIZE;
	if (map->heigh < WINDOW_HEIGH)
		map->heigh = WINDOW_HEIGH;
	if (map->heigh > INT_MAX || map->width > INT_MAX)
	{
		ft_putstr_fd("Error\nMap too large\n", STDERR_FILENO);
		free_mlx(mlx);
		free(map->str);
		exit(EXIT_FAILURE);
	}
	map->img.ptr = mlx_new_image(mlx, (int)map->width, (int)map->heigh);
	if (!map->img.ptr)
	{
		ft_putstr_fd("Error\nFailed to create map image\n", STDERR_FILENO);
		free_mlx(mlx);
		free(map->str);
		exit(EXIT_FAILURE);
	}
	get_img(&map->img);
	put_tiles(mlx, *map);
}
