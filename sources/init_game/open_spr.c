/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_spr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:08:44 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/19 13:43:16 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

static t_img	open_img(void *mlx, char *filename)
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

bool	open_spr_1(void *mlx, t_spr_1 *i1)
{
	const char	*filename[] = {"assets/1/blc.xpm", "assets/1/bm.xpm",
		"assets/1/brc.xpm", "assets/1/hl.xpm", "assets/1/hm.xpm",
		"assets/1/hr.xpm", "assets/1/1.xpm", "assets/1/m.xpm",
		"assets/1/ml.xpm", "assets/1/mr.xpm", "assets/1/tlc.xpm",
		"assets/1/tm.xpm", "assets/1/trc.xpm", "assets/1/vb.xpm",
		"assets/1/vm.xpm", "assets/1/vt.xpm"};
	const t_img	*img[] = {&i1->blc, &i1->bm, &i1->brc, &i1->hl, &i1->hm,
		&i1->hr, &i1->i1, &i1->m, &i1->ml, &i1->mr, &i1->tlc, &i1->tm, &i1->trc,
		&i1->vb, &i1->vm, &i1->vt, NULL};
	size_t		i;

	i = 0;
	while (img[i])
	{
		*(t_img *)img[i] = open_img(mlx, (char *)filename[i]);
		if (!(*img[i]).ptr)
		{
			ft_dprintf(STDERR_FILENO, ERR_OPEN_IMG, filename[i]);
			return (true);
		}
		i++;
	}
	return (false);
}

bool	open_spr(void *mlx, t_spr *spr)
{
	const char	*filename[] = {"assets/0.xpm", "assets/c0.xpm", "assets/c1.xpm",
		"assets/e.xpm", "assets/r.xpm", "assets/player/u0.xpm",
		"assets/player/u1.xpm", "assets/player/l0.xpm", "assets/player/l1.xpm",
		"assets/player/d0.xpm", "assets/player/d1.xpm", "assets/player/r0.xpm",
		"assets/player/r1.xpm", "assets/box/l.xpm", "assets/box/c.xpm",
		"assets/box/r.xpm", "assets/heart.xpm"};
	const t_img	*img[] = {&spr->i0, &spr->c[0],
		&spr->c[1], &spr->e, &spr->r, &spr->player_u[0], &spr->player_u[1],
		&spr->player_l[0], &spr->player_l[1], &spr->player_d[0],
		&spr->player_d[1], &spr->player_r[0], &spr->player_r[1],
		&spr->box_l, &spr->box_c, &spr->box_r, &spr->heart, NULL};
	size_t		i;

	i = 0;
	while (img[i])
	{
		*(t_img *)img[i] = open_img(mlx, (char *)filename[i]);
		if (!(*img[i]).ptr)
		{
			ft_dprintf(STDERR_FILENO, ERR_OPEN_IMG, filename[i]);
			return (true);
		}
		i++;
	}
	return (open_spr_1(mlx, &spr->i1));
}
