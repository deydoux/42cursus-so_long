/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rake.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:44:09 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/28 17:35:06 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	check_rake(t_game *game)
{
	static unsigned int	n = 0;

	if (check_char_contact('R', *game))
	{
		ft_memcpy(&game->pos, &game->map.start, sizeof(game->pos));
		if (game->mov.n != n)
		{
			ft_printf("%sBONK!\n%s", CLEAR_SEQ, game->mov.str);
			if (!--game->health)
			{
				ft_putstr_fd("\nYou lost...", STDOUT_FILENO);
				close_win(game);
			}
			n = game->mov.n;
		}
	}
}
