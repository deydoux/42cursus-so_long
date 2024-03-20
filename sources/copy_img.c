/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:23:03 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/19 13:58:19 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_img(t_img src, t_img dst, size_t x, size_t y)
{
	size_t	width;
	t_dim	pos;

	x *= 4;
	width = src.size.x * 4;
	pos.y = 0;
	while (pos.y < src.size.y)
	{
		pos.x = 0;
		while (pos.x < width)
		{
			dst.buffer[x + pos.x + (y + pos.y) * dst.line_size]
				= src.buffer[pos.x + (pos.y * src.line_size)];
			pos.x++;
		}
		pos.y++;
	}
}
