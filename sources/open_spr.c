/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_spr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:08:44 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/19 13:43:16 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	open_spr(void *mlx, t_spr *spr)
{
	const char	*filename[] = {"assets/empty.xpm", "assets/wall.xpm",
		"assets/collectible.xpm", "assets/exit.xpm",
		"assets/player/u0.xpm", "assets/player/u1.xpm", "assets/player/l0.xpm",
		"assets/player/l1.xpm", "assets/player/d0.xpm", "assets/player/d1.xpm",
		"assets/player/r0.xpm", "assets/player/r1.xpm"};
	const t_img	*img[] = {&spr->empty, &spr->wall, &spr->collectible,
		&spr->exit, &spr->player_u[0], &spr->player_u[1], &spr->player_l[0],
		&spr->player_l[1], &spr->player_d[0], &spr->player_d[1],
		&spr->player_r[0], &spr->player_r[1], NULL};
	size_t		i;

	i = 0;
	while (img[i])
	{
		*(t_img *)img[i] = open_img(mlx, filename[i]);
		if (!(*img[i]).ptr)
		{
			ft_dprintf(STDERR_FILENO, ERR_OPEN_IMG, filename[i]);
			return (true);
		}
		i++;
	}
	return (false);
}
