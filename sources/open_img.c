/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:03:02 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/20 18:14:24 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	open_img(void *mlx, char *filename)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(mlx, filename, &img.width, &img.heigh);
	if (img.ptr)
	{
		img.buffer = mlx_get_data_addr(img.ptr, &img.pixel_bits, &img.line_size,
				&img.endian);
	}
	return (img);
}
