/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:38:19 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/20 15:07:54 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_spr(void *mlx, t_spr spr)
{
	const t_img	*img[] = {&spr.tiles[0], &spr.tiles[1], &spr.c, &spr.e,
		&spr.player_u[0], &spr.player_u[1], &spr.player_l[0], &spr.player_l[1],
		&spr.player_d[0], &spr.player_d[1], &spr.player_r[0], &spr.player_r[1],
		NULL};
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
		if (game.win.frame.ptr)
			mlx_destroy_image(game.mlx, game.win.frame.ptr);
		free_spr(game.mlx, game.spr);
		mlx_destroy_display(game.mlx);
		free(game.mlx);
	}
}
