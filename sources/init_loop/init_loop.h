/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_loop.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:55:06 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/28 13:55:31 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_LOOP_H
# define INIT_LOOP_H
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

enum e_keycode
{
	esc_keycode = 65307
};

int	close_win(t_game *game);
int	key_press(int key, t_game *game);
int	key_release(int key, t_game *game);
int	loop(t_game *game);

#endif
