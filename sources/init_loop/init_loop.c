/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:56:52 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/28 13:12:32 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_loop.h"

void	init_loop(t_game *game)
{
	mlx_hook(game->win.ptr, destroy_notify_event, structure_notify_mask,
		close_win, game);
	mlx_hook(game->win.ptr, key_press_event, key_press_mask, key_press, game);
	mlx_hook(game->win.ptr, key_release_event, key_release_mask, key_release,
		game);
	mlx_loop_hook(game->mlx, loop, game);
	mlx_loop(game->mlx);
}
