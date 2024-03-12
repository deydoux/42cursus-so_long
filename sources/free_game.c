/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:38:19 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/12 19:44:18 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_game game)
{
	free(game.map.str);
	if (game.mlx)
	{
		if (game.map.img.ptr)
			mlx_destroy_image(game.mlx, game.map.img.ptr);
		mlx_destroy_display(game.mlx);
		free(game.mlx);
	}
}
