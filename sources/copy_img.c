/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:23:03 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/14 16:58:02 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_img(t_img src, t_img dst, size_t x, size_t y)
{
	size_t	width;
	size_t	x_src;
	size_t	y_src;

	x *= 4;
	width = src.width * 4;
	y_src = 0;
	while (y_src < src.heigh)
	{
		x_src = 0;
		while (x_src < width)
		{
			dst.buffer[x + x_src + (y + y_src) * dst.line_size]
				= src.buffer[x_src + (y_src * src.line_size)];
			x_src++;
		}
		y_src++;
	}
}
