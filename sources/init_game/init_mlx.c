/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:06:37 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/28 13:06:56 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

bool	init_mlx(void **mlx)
{
	*mlx = mlx_init();
	if (!*mlx)
	{
		ft_putstr_fd(ERR_MLX_INIT, STDERR_FILENO);
		return (true);
	}
	return (false);
}
