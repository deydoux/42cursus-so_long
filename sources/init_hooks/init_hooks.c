/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:56:52 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/12 14:26:48 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_hooks.h"

void	init_hooks(t_game *game)
{
	mlx_hook(game->win.ptr, destroy_notify_event, structure_notify_mask,
		close_window, game);
	mlx_hook(game->win.ptr, key_press_event, key_press_mask, key_press, game);
	mlx_hook(game->win.ptr, key_release_event, key_release_mask, key_release,
		game);
	mlx_loop_hook(game->mlx, loop, game);
}
