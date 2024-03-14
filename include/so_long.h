/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:10:07 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/14 17:28:00 by deydoux          ###   ########.fr       */
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

typedef struct s_img
{
	size_t	heigh;
	size_t	width;
	void	*ptr;
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
}			t_map;

typedef struct s_sprites
{
	bool	alt;
	t_img	collectible;
	t_img	exit;
	t_img	player_up[2];
	t_img	player_left[2];
	t_img	player_down[2];
	t_img	player_right[2];
}			t_sprites;

typedef struct s_win
{
	void	*ptr;
	int		heigh;
	int		width;
}			t_win;

typedef struct s_keys
{
	bool	up;
	bool	left;
	bool	down;
	bool	right;
}			t_keys;

typedef struct s_game
{
	void		*mlx;
	t_win		win;
	t_map		map;
	t_keys		keys;
	t_sprites	sprites;
	size_t		x;
	size_t		y;
}				t_game;

int		close_window(t_game *game);
void	copy_img(t_img src, t_img dst, size_t x, size_t y);
bool	create_map_img(void *mlx, t_map *map);
void	free_game(t_game game);
void	init_hooks(t_game *game);
t_img	new_img(void *mlx, int heigh, int width);
t_img	open_img(void *mlx, const char *filename, int heigh, int width);
bool	open_sprites(void *mlx, t_sprites *sprites);
bool	parse_map(char *filename, t_map *map);
void	put_img(t_img img, t_game game, int x, int y);

#endif
