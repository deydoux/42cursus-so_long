/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char_contact.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:39:20 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/28 13:39:43 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

bool	check_char_contact(char c, t_game game)
{
	int		i;

	i = game.pos.x / IMAGE_SIZE + game.pos.y / IMAGE_SIZE * game.map.width;
	return (game.map.str[i] == c
		|| (game.pos.x % IMAGE_SIZE != 0 && game.map.str[i + 1] == c)
		|| (game.pos.y % IMAGE_SIZE != 0
			&& game.map.str[i + game.map.width] == c));
}
