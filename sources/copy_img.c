/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:23:03 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/22 17:47:42 by deydoux          ###   ########.fr       */
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
	int	null_src_x;
	int	src_x;
	int	src_y;

	null_src_x = (x < 0) * ft_abs(x);
	src_y = (y < 0) * ft_abs(y);
	while (src_y < src.heigh)
	{
		src_x = null_src_x;
		if (y + src_y > dst.heigh)
			return ;
		while (src_x < src.width)
		{
			if (x + src_x > dst.width)
				break ;
			copy_pixel(&src.buffer[src_x * 4 + src_y * src.line_size],
				&dst.buffer[(x + src_x) * 4 + (y + src_y) * dst.line_size]);
			src_x++;
		}
		src_y++;
	}
}
