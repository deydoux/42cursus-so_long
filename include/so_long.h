/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:10:07 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/27 07:04:23 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>

# define OVERLAYS_SIZE 16
# define PLAYER_SIZE 16
# define TILES_SIZE 32

# define WINDOW_HEIGH 720
# define WINDOW_WIDTH 1280

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

typedef struct s_map
{
	char	*str;
	size_t	width;
}			t_map;

typedef struct s_parse
{
	bool	collectible;
	bool	exit;
	bool	start;
	bool	last;
}			t_parse;

typedef struct s_win
{
	void	*mlx;
	void	*ptr;
}			t_win;

int		close_window(t_win *win);
int		key_release(int key, t_win *win);
void	parse_map(char *path, t_map *map);
void	valid_path(t_map *map);

#endif
