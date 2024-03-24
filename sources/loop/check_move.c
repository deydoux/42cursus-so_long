/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:30:02 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/24 20:23:14 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	check_move(t_game *game)
{
	t_pos	move;

	move.x = (game->key.r + (game->key.l * -1)) * SPEED;
	move.y = (game->key.d + (game->key.u * -1)) * SPEED;
	if (game->map.str[(game->pos.x + move.x + IMAGE_SIZE * (move.x > 0)) / IMAGE_SIZE + game->pos.y / IMAGE_SIZE * (game->map.width + 1)] == '1'
		|| game->map.str[(game->pos.x + move.x + IMAGE_SIZE * (move.x > 0)) / IMAGE_SIZE + (game->pos.y + IMAGE_SIZE) / IMAGE_SIZE * (game->map.width + 1)] == '1')
		move.x = 0;
	game->pos.x += move.x;
	if (game->map.str[game->pos.x / IMAGE_SIZE + (game->pos.y + move.y + IMAGE_SIZE * (move.y > 0)) / IMAGE_SIZE * (game->map.width + 1)] == '1'
		|| game->map.str[(game->pos.x + IMAGE_SIZE) / IMAGE_SIZE + (game->pos.y + move.y + IMAGE_SIZE * (move.y > 0)) / IMAGE_SIZE * (game->map.width + 1)] == '1')
		move.y = 0;
	game->pos.y += move.y;
}
