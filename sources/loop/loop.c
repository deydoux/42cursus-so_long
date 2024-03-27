/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:36:59 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/27 18:28:53 by deydoux          ###   ########.fr       */
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

static bool	check_char(char c, t_game game)
{
	int		i;

	i = game.pos.x / IMAGE_SIZE + game.pos.y / IMAGE_SIZE * game.map.width;
	return (game.map.str[i] == c
		|| (game.pos.x % IMAGE_SIZE != 0 && game.map.str[i + 1] == c)
		|| (game.pos.y % IMAGE_SIZE != 0
			&& game.map.str[i + game.map.width] == c));
}

static void	check_exit(t_game game)
{
	t_list	*collects;

	if (!check_char('E', game))
		return ;
	collects = game.map.collects;
	while (collects)
	{
		if (((t_collect *)collects->content)->active)
			return ;
		collects = collects->next;
	}
	ft_putstr_fd("\nYou won!", STDOUT_FILENO);
	close_win(&game);
}

int	loop(t_game *game)
{
	check_move(game);
	check_collect(*game);
	if (check_char('R', *game))
	{
		ft_putstr_fd("\nBONK!", STDOUT_FILENO);
		close_win(game);
	}
	check_exit(*game);
	render_frame(*game);
	mlx_put_image_to_window(game->mlx, game->win.ptr, game->win.frame.ptr, 0,
		0);
	mlx_string_put(game->mlx, game->win.ptr, CHAR_WIDTH, CHAR_HEIGH * 2,
		TEXT_COLOR, game->mov.str);
	return (0);
}
