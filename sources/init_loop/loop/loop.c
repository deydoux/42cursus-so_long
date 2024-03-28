/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:36:59 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/28 13:50:05 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

int	loop(t_game *game)
{
	check_move(game);
	check_collect(*game);
	check_rake(game);
	check_exit(*game);
	render_frame(*game);
	mlx_put_image_to_window(game->mlx, game->win.ptr, game->win.frame.ptr, 0,
		0);
	mlx_string_put(game->mlx, game->win.ptr, CHAR_WIDTH, CHAR_HEIGH * 2,
		TEXT_COLOR, game->mov.str);
	return (0);
}
