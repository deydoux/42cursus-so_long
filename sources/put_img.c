/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:39:33 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/20 18:15:52 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_color(t_img img, size_t x, size_t y)
{
	size_t	pixel;

	pixel = x * 4 + y * img.line_size;
	if (img.endian)
		return ((img.buffer[pixel] << 24)
			+ (img.buffer[pixel + 1] << 16)
			+ (img.buffer[pixel + 2] << 8)
			+ img.buffer[pixel + 3]);
	else
		return (img.buffer[pixel]
			+ (img.buffer[pixel + 1] << 8)
			+ (img.buffer[pixel + 2] << 16)
			+ (img.buffer[pixel + 3] << 24));
}

static void	put_pixel(int color, t_game game, int x, int y)
{
	if (x < 0 || y < 0
		|| x >= (int)game.win.frame.width || y >= (int)game.win.frame.heigh
		|| ((game.map.img.endian && !(color >> 24))
			|| (!game.map.img.endian && !(color & 0xFF))))
		return ;
	mlx_pixel_put(game.mlx, game.win.ptr, x, y, color);
}

void	put_img(t_img img, t_game game, int x, int y)
{
	int	img_x;
	int	img_y;

	img_y = 0;
	while (img_y < img.heigh)
	{
		img_x = 0;
		while (img_x < img.width)
		{
			put_pixel(get_color(img, img_x, img_y), game, x + img_x, y + img_y);
			img_x++;
		}
		img_y++;
	}
}
