/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_spr_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:12:55 by deydoux           #+#    #+#             */
/*   Updated: 2025/01/09 16:25:23 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_spr_1(void *mlx, t_spr_1 *i1)
{
	const t_img	*img[] = {&i1->blc, &i1->bm, &i1->brc, &i1->hl, &i1->hm,
		&i1->hr, &i1->i1, &i1->m, &i1->ml, &i1->mr, &i1->tlc, &i1->tm, &i1->trc,
		&i1->vb, &i1->vm, &i1->vt, NULL};
	size_t		i;

	i = 0;
	while (img[i])
	{
		if ((*img[i]).ptr)
			mlx_destroy_image(mlx, (*img[i]).ptr);
		((t_img *)img[i++])->ptr = NULL;
	}
}
