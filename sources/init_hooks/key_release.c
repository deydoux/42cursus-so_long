/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:27:29 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/19 15:25:52 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_hooks.h"

int	key_release(int key, t_game *game)
{
	if (key == esc_key)
		close_win(game);
	else if (key == KEY_UP)
		game->key.u = false;
	else if (key == KEY_LEFT)
		game->key.l = false;
	else if (key == KEY_DOWN)
		game->key.d = false;
	else if (key == KEY_RIGHT)
		game->key.r = false;
	return (0);
}
