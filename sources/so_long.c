/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:08:20 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/12 10:42:40 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	valid_extention(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (false);
	return (!ft_strncmp(filename + len - 4, ".ber", 4));
}

static bool	new_window(void *mlx, void **win)
{
	*win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGH, WINDOW_TITLE);
	if (!*win)
	{
		ft_putstr_fd(ERR_NEW_WIN, STDERR_FILENO);
		return (true);
	}
	return (false);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || !valid_extention(argv[1]))
	{
		ft_dprintf(STDERR_FILENO, ERR_USAGE, argv[0]);
		return (EXIT_FAILURE);
	}
	if (parse_map(argv[1], &game.map))
		return (EXIT_FAILURE);
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		ft_putstr_fd(ERR_MLX_INIT, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (create_map_img(game.mlx, &game.map) || new_window(game.mlx, &game.win))
	{
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		free(game.map.str);
		return (EXIT_FAILURE);
	}
	mlx_put_image_to_window(game.mlx, game.win, game.map.img.ptr, 0, 0);
	ft_bzero(&game.keys, sizeof(game.keys));
	init_hooks(&game);
	mlx_loop(game.mlx);
	mlx_destroy_image(game.mlx, game.map.img.ptr);
	mlx_destroy_display(game.mlx);
	free(game.mlx);
	free(game.map.str);
	return (EXIT_SUCCESS);
}
