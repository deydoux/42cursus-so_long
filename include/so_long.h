/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:10:07 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/28 17:22:32 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "so_long_errors.h"
# include "so_long_params.h"
# include "libft.h"
# include "mlx.h"
# include <errno.h>
# include <fcntl.h>

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_img
{
	void	*ptr;
	int		heigh;
	int		width;
	char	*buffer;
	int		pixel_bits;
	int		line_size;
	int		endian;
}	t_img;

typedef struct s_collect
{
	bool	active;
	t_pos	pos;
}	t_collect;

typedef struct s_map
{
	char	*str;
	size_t	heigh;
	size_t	width;
	t_img	img;
	t_pos	start;
	t_list	*collects;
}	t_map;

typedef struct s_spr
{
	t_img	tiles[2];
	t_img	c[2];
	t_img	e;
	t_img	r;
	t_img	player_u[2];
	t_img	player_l[2];
	t_img	player_d[2];
	t_img	player_r[2];
	t_img	box_l;
	t_img	box_c;
	t_img	box_r;
}	t_spr;

typedef struct s_win
{
	void	*ptr;
	t_img	frame;
}	t_win;

typedef struct s_key
{
	bool	u;
	bool	l;
	bool	d;
	bool	r;
	char	last;
}	t_key;

typedef struct s_mov
{
	unsigned int	n;
	char			direction;
	char			str[MOV_STR_SIZE];
}	t_mov;

typedef struct s_game
{
	void	*mlx;
	t_map	map;
	t_spr	spr;
	t_win	win;
	t_key	key;
	t_pos	pos;
	t_mov	mov;
	char	health;
}	t_game;

void	copy_img(t_img src, t_img dst, int x, int y);
void	free_game(t_game game);
bool	init_game(int argc, char **argv, t_game *game);
void	init_loop(t_game *game);

#endif
