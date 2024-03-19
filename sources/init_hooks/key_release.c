/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:27:29 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/19 13:52:30 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_hooks.h"

int	key_release(int key, t_game *game)
{
	if (key == esc_key)
		close_win(game);
	else if (key == KEY_UP)
		game->key.up = false;
	else if (key == KEY_LEFT)
		game->key.left = false;
	else if (key == KEY_DOWN)
		game->key.down = false;
	else if (key == KEY_RIGHT)
		game->key.right = false;
	return (0);
}
