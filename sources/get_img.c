/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:53:21 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/28 16:17:26 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_img(t_img *img)
{
	img->buffer = mlx_get_data_addr(img->ptr, &img->pixel_bits, &img->line_size,
			&img->endian);
}
