/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:36:59 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/18 16:05:48 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_hooks.h"

static char	get_player_direction(t_keys keys)
{
	static char	direction = 'd';

	if ((keys.up ^ keys.down) + (keys.left ^ keys.right) == 1)
	{
		if (keys.up ^ keys.down)
		{
			if (keys.up)
				direction = 'u';
			else
				direction = 'd';
		}
		else if (keys.left ^ keys.right)
		{
			if (keys.left)
				direction = 'l';
			else
				direction = 'r';
		}
	}
	else if (direction == 'u' && keys.down)
		direction = 'd';
	else if (keys.up)
		direction = 'u';
	return (direction);
}

static void	put_player(t_game game)
{
	char	direction;
	t_img	sprite;

	direction = get_player_direction(game.keys);
	if (direction == 'u')
		sprite = game.sprites.player_up
		[ft_abs(game.position.y / IMAGE_SIZE % 2)];
	else if (direction == 'l')
		sprite = game.sprites.player_left
		[ft_abs(game.position.x / IMAGE_SIZE % 2)];
	else if (direction == 'r')
		sprite = game.sprites.player_right
		[ft_abs(game.position.x / IMAGE_SIZE % 2)];
	else
		sprite = game.sprites.player_down
		[ft_abs(game.position.y / IMAGE_SIZE % 2)];
	put_img(sprite, game, game.win.width / 2 - IMAGE_SIZE / 2,
		game.win.heigh / 2 - IMAGE_SIZE / 2);
}

int	loop(t_game *game)
{
	static char	i = 0;
	bool		update;

	update = (game->keys.left ^ game->keys.right)
		|| (game->keys.up ^ game->keys.down);
	if (update)
	{
		if (i++ % 64)
			return (0);
		game->position.x += game->keys.left + (game->keys.right * -1);
		game->position.y += game->keys.up + (game->keys.down * -1);
		mlx_put_image_to_window(game->mlx, game->win.ptr, game->map.img.ptr,
			game->position.x, game->position.y);
		put_player(*game);
	}
	return (0);
}
