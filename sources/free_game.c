/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:38:19 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/19 13:49:05 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_spr(void *mlx, t_spr spr)
{
	const t_img	*img[] = {&spr.collectible, &spr.empty, &spr.exit,
		&spr.player_up[0], &spr.player_up[1], &spr.player_left[0],
		&spr.player_left[1], &spr.player_down[0],
		&spr.player_down[1], &spr.player_right[0],
		&spr.player_right[1], &spr.wall, NULL};
	size_t		i;

	i = 0;
	while (img[i])
	{
		if ((*img[i]).ptr)
			mlx_destroy_image(mlx, (*img[i]).ptr);
		i++;
	}
}

void	free_game(t_game game)
{
	free(game.map.str);
	ft_lstclear(&game.map.collectibles, free);
	if (game.mlx)
	{
		if (game.map.img.ptr)
			mlx_destroy_image(game.mlx, game.map.img.ptr);
		free_spr(game.mlx, game.spr);
		mlx_destroy_display(game.mlx);
		free(game.mlx);
	}
}
