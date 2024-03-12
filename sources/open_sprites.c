/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:08:44 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/12 16:13:50 by deydoux          ###   ########.fr       */
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
	const void	*ptr[] = {&sprites->collectible, &sprites->exit,
		&sprites->player_down[0], &sprites->player_down[1],
		&sprites->player_left[0], &sprites->player_left[1],
		&sprites->player_right[0], &sprites->player_right[1],
		&sprites->player_up[0], &sprites->player_up[1], NULL};
	size_t		i;
	int			size;

	i = 0;
	size = IMAGE_SIZE;
	while (ptr[i])
	{
		*(void **)ptr[i] = mlx_xpm_file_to_image(mlx, (char *)filename[i], &size, &size);
		if (!*(void **)ptr[i])
		{
			ft_dprintf(STDERR_FILENO, ERR_OPEN_IMG, filename[i]);
			while (i--)
				mlx_destroy_image(mlx, *(void **)ptr[i]);
			return (true);
		}
		i++;
	}
	return (false);
}
