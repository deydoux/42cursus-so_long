/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:06:07 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/12 13:51:17 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_hooks.h"

int	key_press(int key, t_game *game)
{
	if (key == KEY_UP)
	{
		game->keys.up = true;
		game->keys.last = 'u';
	}
	else if (key == KEY_LEFT)
	{
		game->keys.left = true;
		game->keys.last = 'l';
	}
	else if (key == KEY_DOWN)
	{
		game->keys.down = true;
		game->keys.last = 'd';
	}
	else if (key == KEY_RIGHT)
	{
		game->keys.right = true;
		game->keys.last = 'r';
	}
	return (0);
}
