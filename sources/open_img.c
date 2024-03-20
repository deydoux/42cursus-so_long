/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:03:02 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/19 13:56:03 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	open_img(void *mlx, const char *filename)
{
	t_img	img;
	int		heigh;
	int		width;

	img.ptr = mlx_xpm_file_to_image(mlx, (char *)filename, &width, &heigh);
	if (img.ptr)
	{
		img.size.x = width;
		img.size.y = heigh;
		img.buffer = mlx_get_data_addr(img.ptr, &img.pixel_bits, &img.line_size,
				&img.endian);
	}
	return (img);
}
