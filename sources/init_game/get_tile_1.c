/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tile_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:53:33 by deydoux           #+#    #+#             */
/*   Updated: 2025/01/09 17:06:08 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

static t_img	get_tile_1_bin(int bin, t_spr_1 i1)
{
	const int	config[] = {0b1001, 0b1011, 0b1010, 0b0001, 0b0011, 0b0010,
		0b1111, 0b1101, 0b1110, 0b0101, 0b0111, 0b0110, 0b1000, 0b1100, 0b0100};
	const t_img	img[] = {i1.blc, i1.bm, i1.brc, i1.hl, i1.hm, i1.hr, i1.m,
		i1.ml, i1.mr, i1.tlc, i1.tm, i1.trc, i1.vb, i1.vm, i1.vt};
	size_t		i;

	i = 0;
	while (i < 15)
	{
		if (config[i] == bin)
			return (img[i]);
		i++;
	}
	return (i1.i1);
}

t_img	get_tile_1(t_map map, size_t x, size_t y, t_spr_1 i1)
{
	const bool	top
		= y != 0 && map.str[x + (y - 1) * map.width] == '1';
	const bool	bot
		= y + 1 < map.heigh && map.str[x + (y + 1) * map.width] == '1';
	const bool	left
		= x != 0 && map.str[x - 1 + y * map.width] == '1';
	const bool	right
		= x + 1 < map.width && map.str[x + 1 + y * map.width] == '1';

	return (get_tile_1_bin((top << 3) | (bot << 2) | (left << 1) | right, i1));
}
