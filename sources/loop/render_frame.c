/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:12:31 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/24 15:30:26 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

static char	get_player_direction(t_key key)
{
	static char	direction = 'd';

	if ((key.u ^ key.d) + (key.l ^ key.r) == 1)
	{
		if (key.u ^ key.d)
		{
			if (key.u)
				direction = 'u';
			else
				direction = 'd';
		}
		else if (key.l ^ key.r)
		{
			if (key.l)
				direction = 'l';
			else
				direction = 'r';
		}
	}
	else if (direction == 'u' && key.d)
		direction = 'd';
	else if (key.u)
		direction = 'u';
	return (direction);
}

static t_img	get_player_spr(t_game game)
{
	char	direction;

	direction = get_player_direction(game.key);
	if (direction == 'u')
		return (game.spr.player_u[game.pos.y / IMAGE_SIZE % 2]);
	else if (direction == 'l')
		return (game.spr.player_l[game.pos.x / IMAGE_SIZE % 2]);
	else if (direction == 'r')
		return (game.spr.player_r[game.pos.x / IMAGE_SIZE % 2]);
	else
		return (game.spr.player_d[game.pos.y / IMAGE_SIZE % 2]);
}

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
	copy_img(get_player_spr(game), game.win.frame, game.pos.x + map_pos.x,
		game.pos.y + map_pos.y);
}
