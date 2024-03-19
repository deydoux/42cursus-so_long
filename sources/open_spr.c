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

// static bool	check_spr(t_spr *spr)
// {
// 	if ()
// }

bool	open_spr(void *mlx, t_spr *spr)
{
	const char	*filename[] = {"assets/collectible.xpm", "assets/empty.xpm",
		"assets/exit.xpm", "assets/player/up.xpm", "assets/player/up_alt.xpm",
		"assets/player/left.xpm", "assets/player/left_alt.xpm",
		"assets/player/down.xpm", "assets/player/down_alt.xpm",
		"assets/player/right.xpm", "assets/player/right_alt.xpm",
		"assets/wall.xpm"};
	const t_img	*img[] = {&spr->collectible, &spr->empty, &spr->exit,
		&spr->player_up[0], &spr->player_up[1], &spr->player_left[0],
		&spr->player_left[1], &spr->player_down[0], &spr->player_down[1],
		&spr->player_right[0], &spr->player_right[1], &spr->wall, NULL};
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
