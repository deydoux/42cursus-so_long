/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:36:59 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/04 17:01:38 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loop(t_game *game)
{
	static int	x = 0;
	static int	y = 0;

	if (game->keys.up ^ game->keys.down)
	{
		if (game->keys.up)
			y++;
		else
			y--;
	}
	if (game->keys.left ^ game->keys.right)
	{
		if (game->keys.left)
			x++;
		else
			x--;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->map.img.ptr, x, y);
	return (0);
}
