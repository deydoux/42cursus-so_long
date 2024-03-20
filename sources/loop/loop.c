/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:36:59 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/20 13:59:06 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

static char	get_player_direction(t_key key)
{
	static char	direction = 'd';

	if ((key.u ^ key.d) + (key.l ^ key.r) == 1)
	{
		if (key.u ^ key.d)
		{
			if (key.u)
				direction = 'u';
			else
				direction = 'd';
		}
		else if (key.l ^ key.r)
		{
			if (key.l)
				direction = 'l';
			else
				direction = 'r';
		}
	}
	else if (direction == 'u' && key.d)
		direction = 'd';
	else if (key.u)
		direction = 'u';
	return (direction);
}

static void	put_player(t_game game)
{
	char	direction;
	t_img	sprite;

	direction = get_player_direction(game.key);
	if (direction == 'u')
		sprite = game.spr.player_u[ft_abs(game.pos.y / IMAGE_SIZE % 2)];
	else if (direction == 'l')
		sprite = game.spr.player_l[ft_abs(game.pos.x / IMAGE_SIZE % 2)];
	else if (direction == 'r')
		sprite = game.spr.player_r[ft_abs(game.pos.x / IMAGE_SIZE % 2)];
	else
		sprite = game.spr.player_d[ft_abs(game.pos.y / IMAGE_SIZE % 2)];
	put_img(sprite, game, game.win.width / 2 - IMAGE_SIZE / 2,
		game.win.heigh / 2 - IMAGE_SIZE / 2);
}

int	loop(t_game *game)
{
	static char	i = 0;

	if ((game->key.l ^ game->key.r)
		|| (game->key.u ^ game->key.d))
	{
		if (i++ % 64)
			return (0);
		if (game->key.l ^ game->key.r)
		{
			game->pos.x += game->key.l + (game->key.r * -1);
			if (game->pos.x % IMAGE_SIZE == 0)
				ft_printf("\r%u moves", ++game->moves);
		}
		if (game->key.u ^ game->key.d)
		{
			game->pos.y += game->key.u + (game->key.d * -1);
			if (game->pos.y % IMAGE_SIZE == 0)
				ft_printf("\r%u moves", ++game->moves);
		}
		mlx_put_image_to_window(game->mlx, game->win.ptr, game->map.img.ptr,
			game->pos.x, game->pos.y);
		put_player(*game);
	}
	return (0);
}
