/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:36:59 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/04 17:53:59 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loop(t_game *game)
{
	static int	x = 0;
	static int	y = 0;
	bool		update;

	update = false;
	if (game->keys.up ^ game->keys.down)
	{
		update = true;
		if (game->keys.up)
			y++;
		else
			y--;
	}
	if (game->keys.left ^ game->keys.right)
	{
		update = true;
		if (game->keys.left)
			x++;
		else
			x--;
	}
	if (update)
		mlx_put_image_to_window(game->mlx, game->win, game->map.img.ptr, x, y);
	return (0);
}
