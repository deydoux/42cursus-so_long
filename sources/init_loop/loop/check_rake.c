/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rake.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:44:09 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/28 15:19:51 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	check_rake(t_game *game)
{
	static unsigned int	n = 0;

	if (check_char_contact('R', *game))
	{
		if (game->hard)
		{
			ft_putstr_fd("\nBONK! You lost...", STDOUT_FILENO);
			close_win(game);
		}
		ft_memcpy(&game->pos, &game->map.start, sizeof(game->pos));
		if (game->mov.n != n)
		{
			ft_printf("\nBONK!\n%s", game->mov.str);
			n = game->mov.n;
		}
	}
}
