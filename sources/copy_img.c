/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:23:03 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/27 11:59:14 by deydoux          ###   ########.fr       */
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
	int	min_src_x;
	int	src_x;
	int	src_y;

	min_src_x = x * -1 * (x < 0);
	src_y = y * -1 * (y < 0);
	while (src_y < src.heigh && y + src_y < dst.heigh)
	{
		src_x = min_src_x;
		while (src_x < src.width && x + src_x < dst.width)
		{
			copy_pixel(&src.buffer[src_x * 4 + src_y * src.line_size],
				&dst.buffer[(x + src_x) * 4 + (y + src_y) * dst.line_size]);
			src_x++;
		}
		src_y++;
	}
}
