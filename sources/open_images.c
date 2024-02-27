/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 07:14:52 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/27 13:49:31 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	throw_error(void *mlx, char *map_str)
{
	ft_putstr_fd("Error\nFailed to open images\n", STDERR_FILENO);
	free(map_str);
	free_mlx(mlx);
	exit(EXIT_FAILURE);
}

void	open_images(void *mlx, char *map_str, t_img *img)
{
	const char	*files[] = {"assets/empty.xpm", "assets/player/back.xpm",
		"assets/player/face.xpm", "assets/player/move.xpm",
		"assets/player/side.xpm", "assets/collectible.xpm", "assets/exit.xpm",
		"assets/wall.xpm", NULL};
	const void	*img_ptr[] = {img->empty, img->player_back, img->player_face,
		img->player_move, img->player_side, img->collectible, img->exit,
		img->wall};
	int			size;
	size_t		i;

	size = IMAGE_SIZE;
	i = 0;
	while (files[i])
	{
		img_ptr[i] = mlx_xpm_file_to_image(mlx, (char *)files[i], &size, &size);
		if (!img_ptr[i])
		{
			while (i--)
				mlx_destroy_image(mlx, (void *)img_ptr[i]);
			throw_error(mlx, map_str);
		}
	}
}
