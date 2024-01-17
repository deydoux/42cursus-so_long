/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:27:29 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/17 16:29:38 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_release(int key, t_win *win)
{
	ft_putnbr_fd(key, 1);
	ft_putchar_fd('\n', 1);
	if (key == esc_key)
		close_window(win);
	return (0);
}
