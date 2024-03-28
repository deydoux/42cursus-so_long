/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:23:48 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/28 14:05:57 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_GAME_H
# define INIT_GAME_H
# include "so_long.h"

bool	check_args(int argc, char **argv);
bool	new_win(void *mlx, t_map map, t_win *win);
bool	init_map_img(void *mlx, t_spr *spr, t_map *map);
bool	init_mlx(void **mlx);
t_img	new_img(void *mlx, int heigh, int width);
bool	open_spr(void *mlx, t_spr *spr);
bool	parse_map(char *filename, t_map *map);

#endif
