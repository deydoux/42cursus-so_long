/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:12:31 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/22 18:39:23 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	render_frame(t_game game)
{
	t_pos	map_pos;

	if (game.pos.x > 0)
		map_pos.x = 0;
	else if (game.map.img.width + game.pos.x < game.win.frame.width)
		map_pos.x = (game.map.img.width - game.win.frame.width) * -1;
	else
		map_pos.x = game.pos.x;
	if (game.pos.y > 0)
		map_pos.y = 0;
	else if (game.map.img.heigh + game.pos.y < game.win.frame.heigh)
		map_pos.y = (game.map.img.heigh - game.win.frame.heigh) * -1;
	else
		map_pos.y = game.pos.y;
	copy_img(game.map.img, game.win.frame, map_pos.x, map_pos.y);
}
