/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 07:14:52 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/27 07:44:48 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	open_overlays_images(void *mlx, t_img *img)
{
	const char	*path[] = {"assets/overlays/collectible.xpm",
		"assets/overlays/exit.xpm"};
	const void	*ptr[] = {img->collectible, img->exit, NULL};
	const int	size = OVERLAYS_IMAGE_SIZE;
	size_t		i;

	i = 0;
	while (ptr[i])
	{
		ptr[i] = mlx_xpm_file_to_image(mlx, (char *)path[i],
				(int *)&size, (int *)&size);
		i++;
	}
}

static void	open_player_images(void *mlx, t_img *img)
{
	const char	*path[] = {"assets/player/back.xpm",
		"assets/player/face.xpm", "assets/player/move.xpm",
		"assets/player/side.xpm"};
	const void	*ptr[] = {img->player_back, img->player_face,
		img->player_move, img->player_side, NULL};
	const int	size = PLAYER_IMAGE_SIZE;
	size_t		i;

	i = 0;
	while (ptr[i])
	{
		ptr[i] = mlx_xpm_file_to_image(mlx, (char *)path[i],
				(int *)&size, (int *)&size);
		i++;
	}
}

static void	open_tiles_images(void *mlx, t_img *img)
{
	const char	*path[] = {"assets/tiles/empty.xpm",
		"assets/tiles/wall.xpm"};
	const void	*ptr[] = {img->empty, img->wall, NULL};
	const int	size = TILES_IMAGE_SIZE;
	size_t		i;

	i = 0;
	while (ptr[i])
	{
		ptr[i] = mlx_xpm_file_to_image(mlx, (char *)path[i],
				(int *)&size, (int *)&size);
		i++;
	}
}

void	open_images(void *mlx, t_img *img)
{
	open_overlays_images(mlx, img);
	open_player_images(mlx, img);
	open_tiles_images(mlx, img);
}
