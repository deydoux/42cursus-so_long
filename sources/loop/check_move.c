/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:30:02 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/26 18:41:17 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

static char	get_direction(t_pos move, char last_key)
{
	static char	direction = 'd';
	char		x_direction;
	char		y_direction;

	if (move.x > 0)
		x_direction = 'r';
	else if (move.x < 0)
		x_direction = 'l';
	else
		x_direction = 0;
	if (move.y > 0)
		y_direction = 'd';
	else if (move.y < 0)
		y_direction = 'u';
	else
		y_direction = 0;
	if (x_direction && (x_direction == last_key || !y_direction))
		direction = x_direction;
	else if (y_direction && (y_direction == last_key || !x_direction))
		direction = y_direction;
	return (direction);
}

static void	count_move(t_pos move, t_game *game)
{
	int	n;

	n = 0;
	if (move.x)
		n += game->pos.x % IMAGE_SIZE == 0;
	if (move.y)
		n += game->pos.y % IMAGE_SIZE == 0;
	if (n)
	{
		game->mov.count += n;
		ft_printf("\r%u moves", game->mov.count);
	}
}

void	check_move(t_game *game)
{
	t_pos	move;
	int		i;

	move.x = game->key.r + (game->key.l * -1);
	move.y = game->key.d + (game->key.u * -1);
	i = (game->pos.x + move.x + (IMAGE_SIZE - 1) * (move.x > 0)) / IMAGE_SIZE
		+ game->pos.y / IMAGE_SIZE * game->map.width;
	if (game->map.str[i] == '1' || (game->pos.y % IMAGE_SIZE != 0
			&& game->map.str[i + game->map.width] == '1'))
		move.x = 0;
	game->pos.x += move.x;
	i = game->pos.x / IMAGE_SIZE + (game->pos.y + move.y
			+ (IMAGE_SIZE - 1) * (move.y > 0)) / IMAGE_SIZE * game->map.width;
	if (game->map.str[i] == '1' || (game->pos.x % IMAGE_SIZE != 0
			&& game->map.str[i + 1] == '1'))
		move.y = 0;
	game->pos.y += move.y;
	game->direction = get_direction(move, game->key.last);
	count_move(move, game);
}
