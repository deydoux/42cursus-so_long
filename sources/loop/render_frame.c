/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:12:31 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/25 13:44:41 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

static t_img	get_player_spr(t_game game)
{
	if (game.direction == 'u')
		return (game.spr.player_u[game.pos.y / IMAGE_SIZE % 2]);
	else if (game.direction == 'l')
		return (game.spr.player_l[game.pos.x / IMAGE_SIZE % 2]);
	else if (game.direction == 'r')
		return (game.spr.player_r[game.pos.x / IMAGE_SIZE % 2]);
	else
		return (game.spr.player_d[game.pos.y / IMAGE_SIZE % 2]);
}

static void	render_collectibles(t_pos map_pos, t_game game)
{
	static int	i = 0;
	t_pos		pos;

	i++;
	while (game.map.collectibles)
	{
		pos = *(t_pos *)game.map.collectibles->content;
		copy_img(game.spr.c[i / COLLECTIBLE_ALT % 2], game.win.frame,
			pos.x + map_pos.x, pos.y + map_pos.y);
		game.map.collectibles = game.map.collectibles->next;
	}
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
	render_collectibles(map_pos, game);
	copy_img(get_player_spr(game), game.win.frame, game.pos.x + map_pos.x,
		game.pos.y + map_pos.y);
}
