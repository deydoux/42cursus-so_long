/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:08:20 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/28 13:56:56 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	valid_extention(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (len < 4)
		return (false);
	return (!ft_strncmp(path + len - 4, ".ber", 4));
}

static void	new_window(void *mlx, void **win)
{
	*win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGH, WINDOW_TITLE);
	if (!*win)
	{
		ft_putstr_fd("Error\nFailed to create window\n", STDERR_FILENO);
		free_mlx(mlx);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || !valid_extention(argv[1]))
	{
		ft_putstr_fd("Error\nUsage: ./so_long map_file.ber\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	parse_map(argv[1], &game.map);
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		ft_putstr_fd("Error\nFailed to connect to X server\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	new_window(game.mlx, &game.win);
	mlx_hook(game.win, destroy_notify_event, structure_notify_mask,
		close_window, &game);
	mlx_hook(game.win, key_release_event, key_release_mask, key_release, &game);
	mlx_loop(game.mlx);
	free_mlx(game.mlx);
	free(game.map.str);
	exit(EXIT_SUCCESS);
}
