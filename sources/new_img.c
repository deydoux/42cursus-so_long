/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:17:56 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/19 13:58:48 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	new_img(void *mlx, int heigh, int width)
{
	t_img	img;

	img.size.x = width;
	img.size.y = heigh;
	if (heigh > MAX_IMG_DIMENSION || width > MAX_IMG_DIMENSION
		|| heigh * width > MAX_IMG_PIXEL)
	{
		img.ptr = NULL;
		return (img);
	}
	img.ptr = mlx_new_image(mlx, width, heigh);
	if (img.ptr)
		img.buffer = mlx_get_data_addr(img.ptr,
				&img.pixel_bits, &img.line_size, &img.endian);
	return (img);
}
