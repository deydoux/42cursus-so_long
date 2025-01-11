/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:27:29 by deydoux           #+#    #+#             */
/*   Updated: 2025/01/11 18:56:26 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_loop.h"

int	key_release(int key, t_game *game)
{
	if (key == esc_keycode)
		close_win(game);
	else if (key == game->key.conf.u)
		game->key.u = false;
	else if (key == game->key.conf.l)
		game->key.l = false;
	else if (key == game->key.conf.d)
		game->key.d = false;
	else if (key == game->key.conf.r)
		game->key.r = false;
	return (0);
}
