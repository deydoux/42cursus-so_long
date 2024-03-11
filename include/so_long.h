/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:10:07 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/11 14:51:01 by deydoux          ###   ########.fr       */
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

enum e_event
{
	key_press_event = 2,
	key_release_event = 3,
	destroy_notify_event = 17
};

enum e_mask
{
	key_press_mask = (1L<<0),
	key_release_mask = (1L<<1),
	structure_notify_mask = (1L<<17)
};

typedef struct s_img
{
	int		heigh;
	int		width;
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

typedef struct s_keys
{
	bool	up;
	bool	left;
	bool	down;
	bool	right;
}			t_keys;

typedef struct s_game
{
	t_map	map;
	void	*mlx;
	void	*win;
	t_keys	keys;
}			t_game;

int		close_window(t_game *game);
void	create_map_img(void *mlx, t_map *map);
void	free_mlx(void *mlx);
int		key_press(int key, t_game *game);
int		key_release(int key, t_game *game);
int		loop(t_game *game);
t_img	new_img(void *mlx, int heigh, int width);
t_img	open_img(void *mlx, char *path, int heigh, int width);
void	parse_map(char *filename, t_map *map);
void	put_img_to_img(t_img src, t_img dst, size_t x, size_t y);

#endif
