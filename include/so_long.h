/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:10:07 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/22 12:57:04 by deydoux          ###   ########.fr       */
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

enum e_key
{
	esc_key = 65307
};

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_img
{
	void	*ptr;
	int		heigh;
	int		width;
	char	*buffer;
	int		pixel_bits;
	int		line_size;
	int		endian;
}			t_img;

typedef struct s_map
{
	char	*str;
	size_t	heigh;
	size_t	width;
	t_img	img;
	t_list	*collectibles;
}			t_map;

typedef struct s_spr
{
	t_img	tiles[2];
	t_img	c;
	t_img	e;
	t_img	player_u[2];
	t_img	player_l[2];
	t_img	player_d[2];
	t_img	player_r[2];
}			t_spr;

typedef struct s_win
{
	void	*ptr;
	t_img	frame;
}			t_win;

typedef struct s_key
{
	bool	u;
	bool	l;
	bool	d;
	bool	r;
}			t_key;

typedef struct s_game
{
	void	*mlx;
	t_map	map;
	t_spr	spr;
	t_win	win;
	t_key	key;
	t_pos	pos;
	size_t	moves;
	bool	destroy;
}				t_game;

int		close_win(t_game *game);
void	copy_img(t_img src, t_img dst, int x, int y);
void	free_game(t_game game);
void	init_hooks(t_game *game);
bool	init_map_img(void *mlx, t_spr *spr, t_map *map);
int		loop(t_game *game);
t_img	new_img(void *mlx, int heigh, int width);
t_img	open_img(void *mlx, char *filename);
bool	open_spr(void *mlx, t_spr *spr);
bool	parse_map(char *filename, t_map *map);

#endif
