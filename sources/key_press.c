/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:06:07 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/04 16:09:49 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int key, t_game *game)
{
	if (key == KEY_UP)
		game->keys.up = true;
	else if (key == KEY_LEFT)
		game->keys.left = true;
	else if (key == KEY_DOWN)
		game->keys.down = true;
	else if (key == KEY_RIGHT)
		game->keys.right = true;
	return (0);
}
