/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:27:32 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/08 17:58:37 by deydoux          ###   ########.fr       */
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

static void	throw_closed_map(char *filename, size_t i, t_map map)
{
	size_t	len;

	len = map.width + 1;
	free(map.str);
	ft_dprintf(STDERR_FILENO, ERR_CLOSE_MAP, filename,
		i / len + 1, i % len + 1);
	exit(EXIT_FAILURE);
}

static void	check_closed_map(char *filename, t_map map)
{
	size_t	i;

	i = 0;
	while (map.str[i] == '1')
		i++;
	if (map.str[i] != '\n')
		throw_closed_map(filename, i, map);
	while (map.str[i])
	{
		if (map.str[i] == '\n')
		{
			if (!map.str[i + 1])
			{
				while (map.str[--i] != '\n')
					if (map.str[i] != '1')
						throw_closed_map(filename, i, map);
				return ;
			}
			if (map.str[i - 1] != '1')
				throw_closed_map(filename, i - 1, map);
			if (map.str[i + 1] != '1')
				throw_closed_map(filename, i + 1, map);
		}
		i++;
	}
}

void	parse_map(char *filename, t_map *map)
{
	read_map(filename, map);
	find_unexpected_character(filename, *map);
	find_components(filename, *map);
	check_closed_map(filename, *map);
	find_valid_path(filename, *map);
}
