/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:36:59 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/24 19:20:41 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

int	loop(t_game *game)
{
	static char	i = 0;

	if (game->destroy)
		close_win(game);
	if (i % 64 == 0)
	{
		// game->pos.x / IMAGE_SIZE + game->pos.y / IMAGE_SIZE * (game->map.width + 1);
		check_move(game);
		render_frame(*game);
		mlx_put_image_to_window(game->mlx, game->win.ptr, game->win.frame.ptr,
			0, 0);
	}
	return (0);
}
