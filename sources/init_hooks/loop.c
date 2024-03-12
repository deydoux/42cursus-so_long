/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:36:59 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/12 12:04:03 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_hooks.h"

int	loop(t_game *game)
{
	static int	x = 0;
	static int	y = 0;
	bool		x_update;
	bool		y_update;

	x_update = game->keys.left ^ game->keys.right;
	y_update = game->keys.up ^ game->keys.down;
	if (x_update)
		x += (2 - y_update) * (game->keys.left + (game->keys.right * -1));
	if (y_update)
		y += (2 - x_update) * (game->keys.up + (game->keys.down * -1));
	if (x_update || y_update)
		mlx_put_image_to_window(game->mlx, game->win, game->map.img.ptr, x, y);
	return (0);
}
