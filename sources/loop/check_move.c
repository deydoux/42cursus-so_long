/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:30:02 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/24 22:39:01 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

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
}
