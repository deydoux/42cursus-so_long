/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:10:07 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/11 15:08:44 by deydoux          ###   ########.fr       */
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
void	init_hooks(t_game *game);
t_img	new_img(void *mlx, int heigh, int width);
t_img	open_img(void *mlx, char *path, int heigh, int width);
void	parse_map(char *filename, t_map *map);
void	put_img_to_img(t_img src, t_img dst, size_t x, size_t y);

#endif
