/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:06:07 by deydoux           #+#    #+#             */
/*   Updated: 2025/01/11 18:56:08 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_loop.h"

int	key_press(int key, t_game *game)
{
	if (key == game->key.conf.u)
		game->key.u = true;
	else if (key == game->key.conf.l)
		game->key.l = true;
	else if (key == game->key.conf.d)
		game->key.d = true;
	else if (key == game->key.conf.r)
		game->key.r = true;
	return (0);
}
