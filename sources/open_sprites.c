/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:08:44 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/17 22:29:50 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	open_sprites(void *mlx, t_sprites *dst)
{
	const char	*filename[] = {"assets/collectible.xpm", "assets/empty.xpm",
		"assets/exit.xpm", "assets/player/up.xpm", "assets/player/up_alt.xpm",
		"assets/player/left.xpm", "assets/player/left_alt.xpm",
		"assets/player/down.xpm", "assets/player/down_alt.xpm",
		"assets/player/right.xpm", "assets/player/right_alt.xpm",
		"assets/wall.xpm"};
	const t_img	*img[] = {&dst->collectible, &dst->empty, &dst->exit,
		&dst->player_up[0], &dst->player_up[1], &dst->player_left[0],
		&dst->player_left[1], &dst->player_down[0], &dst->player_down[1],
		&dst->player_right[0], &dst->player_right[1], &dst->wall, NULL};
	size_t		i;

	i = 0;
	while (img[i])
	{
		*(t_img *)img[i] = open_img(mlx, filename[i], IMAGE_SIZE, IMAGE_SIZE);
		if (!(*img[i]).ptr)
		{
			ft_dprintf(STDERR_FILENO, ERR_OPEN_IMG, filename[i]);
			return (true);
		}
		i++;
	}
	return (false);
}
