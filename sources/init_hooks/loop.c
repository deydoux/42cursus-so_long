/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:36:59 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/14 16:59:53 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_hooks.h"

int	loop(t_game *game)
{
	static int	x = 0;
	static int	y = 0;
	bool		update;

	update = (game->keys.left ^ game->keys.right)
		|| (game->keys.up ^ game->keys.down);
	if (update)
	{
		x += game->keys.left + (game->keys.right * -1);
		y += game->keys.up + (game->keys.down * -1);
		mlx_put_image_to_window(game->mlx, game->win.ptr, game->map.img.ptr, x,
			y);
		put_img(game->sprites.player_down[game->sprites.alt], *game, game->win.width / 2 + IMAGE_SIZE / 2, game->win.heigh / 2 + IMAGE_SIZE / 2);
		game->sprites.alt = !game->sprites.alt;
	}
	return (0);
}
