/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:42:09 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/28 13:43:14 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	check_exit(t_game game)
{
	t_list	*collects;

	if (!check_char_contact('E', game))
		return ;
	collects = game.map.collects;
	while (collects)
	{
		if (((t_collect *)collects->content)->active)
			return ;
		collects = collects->next;
	}
	ft_putstr_fd("\nYou won!", STDOUT_FILENO);
	close_win(&game);
}
