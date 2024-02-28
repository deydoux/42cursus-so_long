/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_to_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:23:03 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/28 18:26:29 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img_to_map(t_img img, t_img map_img, size_t x, size_t y)
{
	size_t	x_img;
	size_t	y_img;

	x *= 4;
	x_img = 0;
	y_img = 0;
	while (y_img < IMAGE_SIZE)
	{
		while (x_img < IMAGE_SIZE * 4)
		{
			map_img.buffer[x + x_img + (y + y_img) * map_img.line_size]
				= img.buffer[x_img + (y_img * img.line_size)];
			x_img++;
		}
		x_img = 0;
		y_img++;
	}
}
