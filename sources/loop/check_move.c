/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:30:02 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/22 11:44:36 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	check_move(t_game *game)
{
	t_pos	move;

	move.x = game->key.l + (game->key.r * -1);
	move.y = game->key.u + (game->key.d * -1);
	if (move.x == 1 && game->pos.x + )
}
