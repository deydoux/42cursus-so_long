/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:56:01 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/27 17:37:27 by deydoux          ###   ########.fr       */
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

bool	check_closed_map(t_map map, char *filename);
bool	check_map_components(t_map map, char *filename);
bool	check_valid_path(t_map map, char *filename);
bool	find_collects(t_map *map, char *filename);
bool	read_map(char *filename, t_map *map);

#endif
