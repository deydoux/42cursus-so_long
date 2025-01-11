/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:24:32 by deydoux           #+#    #+#             */
/*   Updated: 2025/01/11 18:54:11 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

bool	init_game(int argc, char **argv, t_game *game)
{
	char	*filename;

	ft_bzero(game, sizeof(*game));
	if (check_args(argc, argv, &filename) || init_key_conf(argc, argv, game)
		|| parse_map(filename, &game->map))
		return (true);
	ft_memcpy(&game->pos, &game->map.start, sizeof(game->pos));
	game->health = 3;
	return (init_mlx(&game->mlx)
		|| open_spr(game->mlx, &game->spr)
		|| init_map_img(game->mlx, &game->spr, &game->map)
		|| new_win(game->mlx, game->map, &game->win));
}
