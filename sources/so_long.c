/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:08:20 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/19 15:23:43 by deydoux          ###   ########.fr       */
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

static bool	new_win(void *mlx, t_map map, t_win *win)
{
	if (map.img.size.y < MAX_WINDOW_HEIGH)
		win->heigh = map.img.size.y;
	else
		win->heigh = MAX_WINDOW_HEIGH;
	if (map.img.size.x < MAX_WINDOW_WIDTH)
		win->width = map.img.size.x;
	else
		win->width = MAX_WINDOW_WIDTH;
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
		|| open_spr(game.mlx, &game.spr)
		|| init_map_img(game.mlx, &game.spr, &game.map)
		|| new_win(game.mlx, game.map, &game.win);
	if (!error)
	{
		init_hooks(&game);
		mlx_loop(game.mlx);
	}
	free_game(game);
	return (error);
}
