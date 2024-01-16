/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:08:20 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/16 18:41:09 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_win	win;

	win.mlx = mlx_init();
	win.ptr = mlx_new_window(win.mlx, WINDOW_WIDTH, WINDOW_HEIGH, "so_long");
	mlx_key_hook(win.ptr, deal_key, &win);
	mlx_loop(win.mlx);
}
