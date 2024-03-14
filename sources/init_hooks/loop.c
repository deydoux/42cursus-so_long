/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:36:59 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/14 17:32:02 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_hooks.h"

static void	put_player(t_game game)
{
	static char	last = 'd';
	t_img		sprite;

	if (game.keys.up + game.keys.left + game.keys.down + game.keys.right == 1)
	{
		if (game.keys.up)
			last = 'u';
		else if (game.keys.left)
			last = 'l';
		else if (game.keys.right)
			last = 'r';
		else
			last = 'd';
	}
	if (last == 'u')
		sprite = game.sprites.player_up[game.sprites.alt];
	else if (last == 'l')
		sprite = game.sprites.player_left[game.sprites.alt];
	else if (last == 'd')
		sprite = game.sprites.player_down[game.sprites.alt];
	else if (last == 'r')
		sprite = game.sprites.player_right[game.sprites.alt];
	put_img(sprite, game, game.win.width / 2 - IMAGE_SIZE / 2,
		game.win.heigh / 2 - IMAGE_SIZE / 2);
}

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
		put_player(*game);
		game->sprites.alt = !game->sprites.alt;
	}
	return (0);
}
