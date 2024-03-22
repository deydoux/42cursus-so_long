/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:23:48 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/22 13:33:04 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_GAME_H
# define INIT_GAME_H
# include "so_long.h"

bool	init_map_img(void *mlx, t_spr *spr, t_map *map);
bool	open_spr(void *mlx, t_spr *spr);
bool	parse_map(char *filename, t_map *map);

#endif
