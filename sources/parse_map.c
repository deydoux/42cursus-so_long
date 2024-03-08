/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:27:32 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/08 15:43:32 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	find_unexpected_character(char *filename, t_map map)
{
	size_t	len;
	size_t	i;

	len = map.width + 1;
	i = 0;
	while (map.str[i])
	{
		if (!ft_strchr("01CEP\n", map.str[i]))
		{
			ft_dprintf(STDERR_FILENO, ERR_UEXP_CHAR, map.str[i], filename,
				i / len + 1, i % len + 1);
			free(map.str);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	parse_map(char *filename, t_map *map)
{
	read_map(filename, map);
	find_unexpected_character(filename, *map);
	find_components(filename, *map);
	closed_map(filename, *map);
	find_valid_path(filename, *map);
}
