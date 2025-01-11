/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_key_conf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:33:03 by deydoux           #+#    #+#             */
/*   Updated: 2025/01/11 18:55:01 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

bool	parse_key_conf(int argc, char **argv, t_game *game)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--keys", 6) == 0
			|| ft_strncmp(argv[i], "-k", 2) == 0)
		{
			if (i + 1 >= argc || ft_strlen(argv[i + 1]) != 4)
			{
				ft_dprintf(STDERR_FILENO, ERR_USAGE, argv[0]);
				return (true);
			}
			game->key.conf.u = argv[i + 1][0];
			game->key.conf.l = argv[i + 1][1];
			game->key.conf.d = argv[i + 1][2];
			game->key.conf.r = argv[i + 1][3];
		}
		i++;
	}
	return (false);
}

bool	init_key_conf(int argc, char **argv, t_game *game)
{
	game->key.conf.u = KEY_UP;
	game->key.conf.l = KEY_LEFT;
	game->key.conf.d = KEY_DOWN;
	game->key.conf.r = KEY_RIGHT;
	return (parse_key_conf(argc, argv, game));
}
