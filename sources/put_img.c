/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:39:33 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/14 17:00:09 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_color(t_img img, size_t x, size_t y)
{
	int	pixel;

	pixel = (x * 4) + (y * img.line_size);
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
	if (x < 0 || y < 0 || x >= game.win.width || y >= game.win.heigh
		|| ((game.map.img.endian && !(color >> 24))
			|| (!game.map.img.endian && !(color & 0xFF))))
		return ;
	mlx_pixel_put(game.mlx, game.win.ptr, x, y, color);
}

void	put_img(t_img img, t_game game, int x, int y)
{
	size_t	x_img;
	size_t	y_img;

	y_img = 0;
	while (y_img < img.heigh)
	{
		x_img = 0;
		while (x_img < img.width)
		{
			put_pixel(get_color(img, x_img, y_img), game, x + x_img, y + y_img);
			x_img++;
		}
		y_img++;
	}
}
