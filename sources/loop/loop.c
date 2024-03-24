/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:36:59 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/24 15:27:19 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

int	loop(t_game *game)
{
	static char	i = 0;

	if (game->destroy)
		close_win(game);
	if (i++ % 64 == 0
		&& ((game->key.l ^ game->key.r) || (game->key.u ^ game->key.d)))
	{
		if (game->key.l ^ game->key.r)
		{
			game->pos.x += game->key.r + (game->key.l * -1);
			if (game->pos.x % IMAGE_SIZE == 0)
				ft_printf("\r%u moves", ++game->moves);
		}
		if (game->key.u ^ game->key.d)
		{
			game->pos.y += game->key.d + (game->key.u * -1);
			if (game->pos.y % IMAGE_SIZE == 0)
				ft_printf("\r%u moves", ++game->moves);
		}
		render_frame(*game);
		mlx_put_image_to_window(game->mlx, game->win.ptr, game->win.frame.ptr,
			0, 0);
	}
	return (0);
}
