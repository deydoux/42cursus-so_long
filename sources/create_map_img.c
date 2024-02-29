/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:26:52 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/29 15:20:19 by deydoux          ###   ########.fr       */
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
	size_t	i;

	open_tiles_img(mlx, map.str, img);
	x = 0;
	y = 0;
	i = 0;
	while (map.str[i])
	{
		if (map.str[i] == '\n')
		{
			x = 0;
			y += IMAGE_SIZE;
		}
		else
		{
			put_img_to_img(img[map.str[i] == '1'], map.img, x, y);
			x += IMAGE_SIZE;
		}
		i++;
	}
	mlx_destroy_image(mlx, img[0].ptr);
	mlx_destroy_image(mlx, img[1].ptr);
}

void	create_map_img(void *mlx, t_map *map)
{
	map->width = WINDOW_WIDTH;
	map->heigh = WINDOW_HEIGH;
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
