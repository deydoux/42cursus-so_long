/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:08:20 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/17 16:31:47 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_win	win;

	win.mlx = mlx_init();
	win.ptr = mlx_new_window(win.mlx, WINDOW_WIDTH, WINDOW_HEIGH, "so_long");
	mlx_hook(win.ptr, destroy_notify_event, structure_notify_mask, close_window,
		&win);
	mlx_hook(win.ptr, key_release_event, key_release_mask, key_release, &win);
	mlx_loop(win.mlx);
	mlx_destroy_display(win.mlx);
	free(win.mlx);
}
