/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:08:44 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/12 20:25:35 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	open_sprites(void *mlx, t_sprites *sprites)
{
	const char	*filename[] = {"assets/collectible.xpm", "assets/exit.xpm",
		"assets/player/down.xpm", "assets/player/down_alt.xpm",
		"assets/player/left.xpm", "assets/player/left_alt.xpm",
		"assets/player/right.xpm", "assets/player/right_alt.xpm",
		"assets/player/up.xpm", "assets/player/up_alt.xpm"};
	const t_img	*img[] = {&sprites->collectible, &sprites->exit,
		&sprites->player_down[0], &sprites->player_down[1],
		&sprites->player_left[0], &sprites->player_left[1],
		&sprites->player_right[0], &sprites->player_right[1],
		&sprites->player_up[0], &sprites->player_up[1], NULL};
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
