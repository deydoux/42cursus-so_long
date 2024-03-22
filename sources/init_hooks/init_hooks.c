/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:56:52 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/22 12:58:53 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_hooks.h"

static int	destroy_notify(t_game *game)
{
	game->destroy = true;
	return (0);
}

void	init_hooks(t_game *game)
{
	mlx_hook(game->win.ptr, destroy_notify_event, structure_notify_mask,
		destroy_notify, game);
	mlx_hook(game->win.ptr, key_press_event, key_press_mask, key_press, game);
	mlx_hook(game->win.ptr, key_release_event, key_release_mask, key_release,
		game);
	mlx_loop_hook(game->mlx, loop, game);
}
