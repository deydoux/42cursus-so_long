/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:53:24 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/28 13:55:11 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_loop.h"

int	close_win(t_game *game)
{
	ft_putchar_fd('\n', STDOUT_FILENO);
	mlx_destroy_window(game->mlx, game->win.ptr);
	mlx_loop_end(game->mlx);
	free_game(*game);
	exit(EXIT_SUCCESS);
}
