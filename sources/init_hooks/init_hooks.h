/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hooks.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:55:06 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/11 15:04:28 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_HOOKS_H
# define INIT_HOOKS_H
# include "so_long.h"

enum e_event
{
	key_press_event = 2,
	key_release_event = 3,
	destroy_notify_event = 17
};

enum e_mask
{
	key_press_mask = (1L<<0),
	key_release_mask = (1L<<1),
	structure_notify_mask = (1L<<17)
};

int	key_press(int key, t_game *game);
int	key_release(int key, t_game *game);
int	loop(t_game *game);

#endif
