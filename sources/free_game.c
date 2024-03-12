/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:38:19 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/12 20:26:02 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_sprites(void *mlx, t_sprites sprites)
{
	const t_img	*img[] = {&sprites.collectible, &sprites.exit,
		&sprites.player_down[0], &sprites.player_down[1],
		&sprites.player_left[0], &sprites.player_left[1],
		&sprites.player_right[0], &sprites.player_right[1],
		&sprites.player_up[0], &sprites.player_up[1], NULL};
	size_t		i;

	i = 0;
	while (img[i])
		if ((*img[i]).ptr)
			mlx_destroy_image(mlx, (*img[i]).ptr);
}

void	free_game(t_game game)
{
	free(game.map.str);
	if (game.mlx)
	{
		if (game.map.img.ptr)
			mlx_destroy_image(game.mlx, game.map.img.ptr);
		free_sprites(game.mlx, game.sprites);
		mlx_destroy_display(game.mlx);
		free(game.mlx);
	}
}
