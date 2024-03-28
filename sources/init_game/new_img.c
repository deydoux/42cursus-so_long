/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:17:56 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/28 13:59:46 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

t_img	new_img(void *mlx, int heigh, int width)
{
	t_img	img;

	if (heigh > MAX_IMG_DIMENSION || width > MAX_IMG_DIMENSION
		|| heigh * width > MAX_IMG_PIXEL)
	{
		img.ptr = NULL;
		return (img);
	}
	img.heigh = heigh;
	img.width = width;
	img.ptr = mlx_new_image(mlx, width, heigh);
	if (img.ptr)
		img.buffer = mlx_get_data_addr(img.ptr,
				&img.pixel_bits, &img.line_size, &img.endian);
	return (img);
}
