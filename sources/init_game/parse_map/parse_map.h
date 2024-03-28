/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:56:01 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/28 13:01:43 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_H
# define PARSE_MAP_H
# include "../init_game.h"

# ifdef BONUS
#  define MAP_CHARSET	"01CERP\n"
# else
#  define MAP_CHARSET	"01CEP\n"
# endif

bool	check_map_charset(t_map map, char *filename);
bool	check_map_exit(t_map map, char *filename);
bool	check_map_path(t_map map, char *filename);
bool	check_map_size(t_map map);
bool	check_map_walls(t_map map, char *filename);
bool	find_map_collects(t_map *map, char *filename);
bool	find_map_start(t_map *map, char *filename);
bool	read_map_file(char *filename, t_map *map);

#endif
