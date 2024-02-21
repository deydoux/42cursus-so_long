/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:08:20 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/21 18:17:48 by deydoux          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	char	*map;
	t_win	win;

	if (argc != 2 || !valid_extention(argv[1]))
	{
		ft_putstr_fd("Usage: ./so_long map.ber\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	map = parse_map(argv[1]);
	free(map);
	win.mlx = mlx_init();
	win.ptr = mlx_new_window(win.mlx, WINDOW_WIDTH, WINDOW_HEIGH, "so_long");
	mlx_hook(win.ptr, destroy_notify_event, structure_notify_mask, close_window,
		&win);
	mlx_hook(win.ptr, key_release_event, key_release_mask, key_release, &win);
	mlx_loop(win.mlx);
	mlx_destroy_display(win.mlx);
	free(win.mlx);
}
