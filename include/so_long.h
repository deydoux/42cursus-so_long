/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:10:07 by deydoux           #+#    #+#             */
/*   Updated: 2024/01/16 18:35:01 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include "mlx.h"

# define ESC_KEY 65307

# ifndef WINDOW_HEIGH
#  define WINDOW_HEIGH 720
# endif
# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 1280
# endif

typedef struct s_win
{
	void	*mlx;
	void	*ptr;
}			t_win;

int	deal_key(int key, t_win *win);

#endif
