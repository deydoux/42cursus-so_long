/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:23:03 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/22 12:41:51 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	copy_pixel(char *src, char *dst)
{
	if (!src[0])
		return ;
	dst[0] = src[0];
	dst[1] = src[1];
	dst[2] = src[2];
	dst[3] = src[3];
}

void	copy_img(t_img src, t_img dst, int x, int y)
{
	int	src_x;
	int	src_y;

	src_y = 0;
	while (src_y < src.heigh)
	{
		src_x = 0;
		while (src_x < src.width)
		{
			if (0 <= x + src_x && x + src_x <= dst.width
				&& 0 <= y + src_y && y + src_y <= dst.heigh)
				copy_pixel(&src.buffer[src_x * 4 + src_y * src.line_size],
					&dst.buffer[(x + src_x) * 4 + (y + src_y) * dst.line_size]);
			src_x++;
		}
		src_y++;
	}
}
