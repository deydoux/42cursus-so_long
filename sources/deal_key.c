/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:07:25 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/16 18:34:35 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	deal_key(int key, t_win *win)
{
	ft_putnbr_fd(key, 1);
	ft_putchar_fd('\n', 1);
	if (key == ESC_KEY)
		mlx_destroy_display(win->mlx);
	return (0);
}
