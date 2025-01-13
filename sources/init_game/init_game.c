/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:24:32 by deydoux           #+#    #+#             */
/*   Updated: 2025/01/13 13:40:30 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

bool	init_game(int argc, char **argv, t_game *game)
{
	ft_bzero(game, sizeof(*game));
	game->key.conf = (t_key_conf){KEY_UP, KEY_LEFT, KEY_DOWN, KEY_RIGHT};
	if (handle_args(argc, argv, game))
		return (true);
	ft_memcpy(&game->pos, &game->map.start, sizeof(game->pos));
	game->health = 3;
	return (init_mlx(&game->mlx)
		|| open_spr(game->mlx, &game->spr)
		|| init_map_img(game->mlx, &game->spr, &game->map)
		|| new_win(game->mlx, game->map, &game->win));
}
