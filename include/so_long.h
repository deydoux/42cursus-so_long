/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:10:07 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/22 17:24:23 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>

# ifndef WINDOW_HEIGH
#  define WINDOW_HEIGH 720
# endif
# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 1280
# endif

typedef struct s_map
{
	char	*content;
	size_t	line_len;
}			t_map;

typedef struct s_parse
{
	bool	collectible;
	bool	exit;
	bool	start;
}			t_parse;

enum
{
	esc_key = 65307
};

enum
{
	key_press_event = 2,
	key_release_event = 3,
	destroy_notify_event = 17
};

enum
{
	key_press_mask = (1L<<0),
	key_release_mask = (1L<<1),
	structure_notify_mask = (1L<<17)
};

typedef struct s_win
{
	void	*mlx;
	void	*ptr;
}			t_win;

int		close_window(t_win *win);
int		key_release(int key, t_win *win);
t_map	parse_map(char *path);

#endif
