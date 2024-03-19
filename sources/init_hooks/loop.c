/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:36:59 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/19 13:50:08 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_hooks.h"

static char	get_player_direction(t_key key)
{
	static char	direction = 'd';

	if ((key.up ^ key.down) + (key.left ^ key.right) == 1)
	{
		if (key.up ^ key.down)
		{
			if (key.up)
				direction = 'u';
			else
				direction = 'd';
		}
		else if (key.left ^ key.right)
		{
			if (key.left)
				direction = 'l';
			else
				direction = 'r';
		}
	}
	else if (direction == 'u' && key.down)
		direction = 'd';
	else if (key.up)
		direction = 'u';
	return (direction);
}

static void	put_player(t_game game)
{
	char	direction;
	t_img	sprite;

	direction = get_player_direction(game.key);
	if (direction == 'u')
		sprite = game.spr.player_up
		[ft_abs(game.pos.y / IMAGE_SIZE % 2)];
	else if (direction == 'l')
		sprite = game.spr.player_left
		[ft_abs(game.pos.x / IMAGE_SIZE % 2)];
	else if (direction == 'r')
		sprite = game.spr.player_right
		[ft_abs(game.pos.x / IMAGE_SIZE % 2)];
	else
		sprite = game.spr.player_down
		[ft_abs(game.pos.y / IMAGE_SIZE % 2)];
	put_img(sprite, game, game.win.width / 2 - IMAGE_SIZE / 2,
		game.win.heigh / 2 - IMAGE_SIZE / 2);
}

int	loop(t_game *game)
{
	static char	i = 0;

	if ((game->key.left ^ game->key.right)
		|| (game->key.up ^ game->key.down))
	{
		if (i++ % 64)
			return (0);
		if (game->key.left ^ game->key.right)
		{
			game->pos.x += game->key.left + (game->key.right * -1);
			if (game->pos.x % IMAGE_SIZE == 0)
				ft_printf("\r%u moves", ++game->moves);
		}
		if (game->key.up ^ game->key.down)
		{
			game->pos.y += game->key.up + (game->key.down * -1);
			if (game->pos.y % IMAGE_SIZE == 0)
				ft_printf("\r%u moves", ++game->moves);
		}
		mlx_put_image_to_window(game->mlx, game->win.ptr, game->map.img.ptr,
			game->pos.x, game->pos.y);
		put_player(*game);
	}
	return (0);
}
