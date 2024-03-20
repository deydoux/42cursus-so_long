/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:10:07 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/20 13:30:30 by deydoux          ###   ########.fr       */
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

typedef struct s_dim
{
	size_t	x;
	size_t	y;
}			t_dim;

typedef struct s_img
{
	void	*ptr;
	t_dim	size;
	char	*buffer;
	int		pixel_bits;
	int		line_size;
	int		endian;
}			t_img;

typedef struct s_map
{
	char	*str;
	t_dim	size;
	t_img	img;
	t_list	*collectibles;
}			t_map;

typedef struct s_spr
{
	t_img	empty;
	t_img	wall;
	t_img	collectible;
	t_img	exit;
	t_img	player_u[2];
	t_img	player_l[2];
	t_img	player_d[2];
	t_img	player_r[2];
}			t_spr;

typedef struct s_win
{
	void	*ptr;
	int		heigh;
	int		width;
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
	t_dim	pos;
	size_t	moves;
}				t_game;

int		close_win(t_game *game);
bool	comp_dim(t_dim dim1, t_dim dim2);
void	copy_img(t_img src, t_img dst, size_t x, size_t y);
void	free_game(t_game game);
void	init_hooks(t_game *game);
bool	init_map_img(void *mlx, t_spr *spr, t_map *map);
t_img	new_img(void *mlx, int heigh, int width);
t_img	open_img(void *mlx, const char *filename);
bool	open_spr(void *mlx, t_spr *spr);
bool	parse_map(char *filename, t_map *map);
void	put_img(t_img img, t_game game, int x, int y);

#endif
