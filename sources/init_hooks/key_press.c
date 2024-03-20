/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:06:07 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/19 15:25:52 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_hooks.h"

int	key_press(int key, t_game *game)
{
	if (key == KEY_UP)
		game->key.u = true;
	else if (key == KEY_LEFT)
		game->key.l = true;
	else if (key == KEY_DOWN)
		game->key.d = true;
	else if (key == KEY_RIGHT)
		game->key.r = true;
	return (0);
}
