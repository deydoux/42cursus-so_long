/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:24:32 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/28 15:16:43 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

bool	init_game(int argc, char **argv, t_game *game)
{
	ft_bzero(game, sizeof(*game));
	if (check_args(argc, argv, &game->hard)
		|| parse_map(argv[1 + (game->hard == 1)], &game->map))
		return (true);
	ft_memcpy(&game->pos, &game->map.start, sizeof(game->pos));
	return (init_mlx(&game->mlx)
		|| open_spr(game->mlx, &game->spr)
		|| init_map_img(game->mlx, &game->spr, &game->map)
		|| new_win(game->mlx, game->map, &game->win));
}
