/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:17:56 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/13 15:37:36 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	new_img(void *mlx, int heigh, int width)
{
	t_img	img;

	img.heigh = heigh;
	img.width = width;
	if (heigh > INT_MAX / 32 || width > INT_MAX / 32)
		img.ptr = NULL;
	else
	{
		img.ptr = mlx_new_image(mlx, width, heigh);
		if (img.ptr)
			img.buffer = mlx_get_data_addr(img.ptr,
					&img.pixel_bits, &img.line_size, &img.endian);
	}
	return (img);
}
