/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:06:07 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/19 13:50:08 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_hooks.h"

int	key_press(int key, t_game *game)
{
	if (key == KEY_UP)
		game->key.up = true;
	else if (key == KEY_LEFT)
		game->key.left = true;
	else if (key == KEY_DOWN)
		game->key.down = true;
	else if (key == KEY_RIGHT)
		game->key.right = true;
	return (0);
}
