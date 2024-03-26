/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:12:31 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/26 21:14:17 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

static void	render_collects(t_pos map_pos, t_game game)
{
	static int	i = 0;
	t_collect	collect;

	i++;
	while (game.map.collects)
	{
		collect = *(t_collect *)game.map.collects->content;
		if (collect.active)
			copy_img(game.spr.c[i / COLLECT_ALT % 2], game.win.frame,
				collect.pos.x + map_pos.x, collect.pos.y + map_pos.y);
		game.map.collects = game.map.collects->next;
	}
}

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

static void	render_box(t_game game)
{
	t_pos	pos;
	size_t	i;

	pos.x = CHAR_WIDTH / 2;
	pos.y = CHAR_HEIGH / 2;
	copy_img(game.spr.box_l, game.win.frame, pos.x, pos.y);
	pos.x += game.spr.box_l.width;
	i = 0;
	while (game.mov.str[i++])
	{
		copy_img(game.spr.box_c, game.win.frame, pos.x, pos.y);
		pos.x += game.spr.box_c.width;
	}
	copy_img(game.spr.box_r, game.win.frame, pos.x, pos.y);
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
	render_collects(map_pos, game);
	copy_img(get_player_spr(game), game.win.frame, game.pos.x + map_pos.x,
		game.pos.y + map_pos.y);
	render_box(game);
}
