/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:27:29 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/11 15:04:13 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_hooks.h"

int	key_release(int key, t_game *game)
{
	if (key == esc_key)
		close_window(game);
	else if (key == KEY_UP)
		game->keys.up = false;
	else if (key == KEY_LEFT)
		game->keys.left = false;
	else if (key == KEY_DOWN)
		game->keys.down = false;
	else if (key == KEY_RIGHT)
		game->keys.right = false;
	return (0);
}
