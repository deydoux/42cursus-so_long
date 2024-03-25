/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:36:59 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/25 18:06:22 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

static void	check_collect(t_game game)
{
	t_collect	*collect;

	while (game.map.collects)
	{
		collect = game.map.collects->content;
		if (collect->active && collect->pos.x - IMAGE_SIZE < game.pos.x
			&& game.pos.x < collect->pos.x + IMAGE_SIZE
			&& collect->pos.y - IMAGE_SIZE < game.pos.y
			&& game.pos.y < collect->pos.y + IMAGE_SIZE)
		{
			collect->active = false;
			return ;
		}
		game.map.collects = game.map.collects->next;
	}
}

int	loop(t_game *game)
{
	check_move(game);
	check_collect(*game);
	render_frame(*game);
	mlx_put_image_to_window(game->mlx, game->win.ptr, game->win.frame.ptr, 0,
		0);
	return (0);
}
