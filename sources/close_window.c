/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:53:24 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/18 17:28:15 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	if (game->moves)
		ft_putchar_fd('\n', STDOUT_FILENO);
	mlx_destroy_window(game->mlx, game->win.ptr);
	mlx_loop_end(game->mlx);
	return (0);
}
