/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:12:31 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/22 17:01:52 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	render_frame(t_game game)
{
	t_pos	map_pos;

	ft_printf("%i\n", game.pos.x);
	if (game.pos.x > 0)
		map_pos.x = 0;
	else if (game.map.img.width + game.pos.x < game.win.frame.width)
		map_pos.x = game.win.frame.width;
	else
		map_pos.x = game.pos.x;
	if (game.pos.y > 0)
		map_pos.y = 0;
	else if (game.map.img.heigh + game.pos.y < game.win.frame.heigh)
		map_pos.y = game.win.frame.heigh;
	else
		map_pos.y = game.pos.y;
	copy_img(game.map.img, game.win.frame, map_pos.x, map_pos.y);
}
