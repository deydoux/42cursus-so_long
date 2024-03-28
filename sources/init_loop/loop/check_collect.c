/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:24:02 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/28 13:24:19 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	check_collect(t_game game)
{
	t_collect	*collect;

	while (game.map.collects)
	{
		collect = game.map.collects->content;
		if (collect->active && collect->pos.x - IMAGE_SIZE < game.pos.x
			&& game.pos.x < collect->pos.x + IMAGE_SIZE
			&& collect->pos.y - IMAGE_SIZE < game.pos.y
			&& game.pos.y < collect->pos.y + IMAGE_SIZE)
		{
			collect->active = false;
			return ;
		}
		game.map.collects = game.map.collects->next;
	}
}
