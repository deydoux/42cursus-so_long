/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:08:20 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/12 20:12:11 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	check_args(int argc, char **argv)
{
	bool	error;
	size_t	len;

	error = argc != 2;
	if (!error)
	{
		len = ft_strlen(argv[1]);
		error = len < 4;
		if (!error)
			error = ft_strncmp(argv[1] + len - 4, ".ber", 4) != 0;
	}
	if (error)
	{
		if (argc)
			ft_dprintf(STDERR_FILENO, ERR_USAGE, argv[0]);
		else
			ft_dprintf(STDERR_FILENO, ERR_USAGE, "so_long");
		return (true);
	}
	return (false);
}

static bool	init_mlx(void **mlx)
{
	*mlx = mlx_init();
	if (!*mlx)
	{
		ft_putstr_fd(ERR_MLX_INIT, STDERR_FILENO);
		return (true);
	}
	return (false);
}

static bool	new_window(void *mlx, t_map map, t_win *win)
{
	if (map.img.heigh < WINDOW_HEIGH)
		win->heigh = map.img.heigh;
	else
		win->heigh = WINDOW_HEIGH;
	if (map.img.width < WINDOW_WIDTH)
		win->width = map.img.width;
	else
		win->width = WINDOW_WIDTH;
	win->ptr = mlx_new_window(mlx, win->width, win->heigh, WINDOW_TITLE);
	if (!win->ptr)
	{
		ft_putstr_fd(ERR_NEW_WIN, STDERR_FILENO);
		return (true);
	}
	return (false);
}

int	main(int argc, char **argv)
{
	t_game	game;
	bool	error;

	ft_bzero(&game, sizeof(game));
	error = check_args(argc, argv)
		|| parse_map(argv[1], &game.map)
		|| init_mlx(&game.mlx)
		|| create_map_img(game.mlx, &game.map)
		|| new_window(game.mlx, game.map, &game.win);
	if (!error)
	{
		init_hooks(&game);
		mlx_loop(game.mlx);
	}
	free_game(game);
	return (error);
}
