/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:53:24 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/27 13:35:46 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_images(void *mlx, t_img img)
{
	mlx_destroy_image(mlx, img.collectible);
	mlx_destroy_image(mlx, img.empty);
	mlx_destroy_image(mlx, img.exit);
	mlx_destroy_image(mlx, img.player_back);
	mlx_destroy_image(mlx, img.player_face);
	mlx_destroy_image(mlx, img.player_move);
	mlx_destroy_image(mlx, img.player_side);
	mlx_destroy_image(mlx, img.wall);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	destroy_images(game->mlx, game->img);
	mlx_loop_end(game->mlx);
	return (0);
}
