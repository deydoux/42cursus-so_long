/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:24:32 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/22 13:29:40 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

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
	int	width;
	int	heigh;

	if (map.img.width < MAX_WINDOW_WIDTH)
		width = map.img.width;
	else
		width = MAX_WINDOW_WIDTH;
	if (map.img.heigh < MAX_WINDOW_HEIGH)
		heigh = map.img.heigh;
	else
		heigh = MAX_WINDOW_HEIGH;
	win->frame = new_img(mlx, heigh, width);
	if (!win->frame.ptr)
	{
		ft_dprintf(STDERR_FILENO, ERR_NEW, "frame");
		return (true);
	}
	win->ptr = mlx_new_window(mlx, width, heigh, WINDOW_TITLE);
	if (!win->ptr)
	{
		ft_dprintf(STDERR_FILENO, ERR_NEW, "window");
		return (true);
	}
	return (false);
}

bool	init_game(int argc, char **argv, t_game *game)
{
	ft_bzero(game, sizeof(*game));
	return (check_args(argc, argv)
		|| parse_map(argv[1], &game->map)
		|| init_mlx(&game->mlx)
		|| open_spr(game->mlx, &game->spr)
		|| init_map_img(game->mlx, &game->spr, &game->map)
		|| new_win(game->mlx, game->map, &game->win));
}
