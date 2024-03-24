/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:12:31 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/24 15:05:23 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	render_frame(t_game game)
{
	t_pos	map_pos;

	map_pos.x = game.pos.x * -1 + (game.win.frame.width - IMAGE_SIZE) / 2;
	map_pos.y = game.pos.y * -1 + (game.win.frame.heigh - IMAGE_SIZE) / 2;
	if (map_pos.x > 0)
		map_pos.x = 0;
	else if (map_pos.x < game.win.frame.width - game.map.img.width)
		map_pos.x = game.win.frame.width - game.map.img.width;
	if (map_pos.y > 0)
		map_pos.y = 0;
	else if (map_pos.y < game.win.frame.heigh - game.map.img.heigh)
		map_pos.y = game.win.frame.heigh - game.map.img.heigh;
	copy_img(game.map.img, game.win.frame, map_pos.x, map_pos.y);
}
