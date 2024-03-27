/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:36:59 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/27 12:33:29 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

static void	check_collect(t_game *game)
{
	t_list		*collects;
	t_collect	*collect;

	collects = game->map.collects.lst;
	while (collects)
	{
		collect = collects->content;
		if (collect->active && collect->pos.x - IMAGE_SIZE < game->pos.x
			&& game->pos.x < collect->pos.x + IMAGE_SIZE
			&& collect->pos.y - IMAGE_SIZE < game->pos.y
			&& game->pos.y < collect->pos.y + IMAGE_SIZE)
		{
			game->map.collects.last = collect;
			collect->active = false;
			return ;
		}
		collects = collects->next;
	}
}

static void	check_exit(t_game game)
{
	int		i;
	t_list	*collects;

	i = game.pos.x / IMAGE_SIZE + game.pos.y / IMAGE_SIZE * game.map.width;
	if (game.map.str[i] == 'E'
		|| (game.pos.x % IMAGE_SIZE != 0 && game.map.str[i + 1] == 'E')
		|| (game.pos.y % IMAGE_SIZE != 0
			&& game.map.str[i + game.map.width] == 'E'))
	{
		collects = game.map.collects.lst;
		while (collects)
		{
			if (((t_collect *)collects->content)->active)
				return ;
			collects = collects->next;
		}
		close_win(&game);
	}
}

int	loop(t_game *game)
{
	check_move(game);
	check_collect(game);
	check_exit(*game);
	render_frame(*game);
	mlx_put_image_to_window(game->mlx, game->win.ptr, game->win.frame.ptr, 0,
		0);
	mlx_string_put(game->mlx, game->win.ptr, CHAR_WIDTH, CHAR_HEIGH * 2,
		TEXT_COLOR, game->mov.str);
	return (0);
}
