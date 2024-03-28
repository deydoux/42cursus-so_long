/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:31:30 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/28 12:31:50 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"

bool	check_map_size(t_map map)
{
	if (map.heigh > MAX_IMG_DIMENSION / IMAGE_SIZE
		|| (map.width - 1) > MAX_IMG_DIMENSION / IMAGE_SIZE
		|| map.heigh * (map.width - 1) > MAX_IMG_PIXEL / IMAGE_SIZE)
	{
		ft_dprintf(STDERR_FILENO, ERR_MAP_SIZE, IMAGE_SIZE);
		return (true);
	}
	return (false);
}
