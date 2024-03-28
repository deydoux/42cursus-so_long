/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:05:28 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/28 13:06:02 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

bool	new_win(void *mlx, t_map map, t_win *win)
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
