/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_components.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:11:59 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/07 15:34:13 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	throw_duplicate(
	char *component, char *filename, char *ptr, t_map map)
{
	size_t	i;
	size_t	len;

	i = ptr - map.str;
	len = map.width + 1;
	free(map.str);
	ft_dprintf(STDERR_FILENO, ERR_DUP_CMPN, component, filename,
		i / len + 1, i % len + 1);
	exit(EXIT_FAILURE);
}

static void	find_duplicate(char *filename, char **components, t_map map)
{
	char	*map_exit;
	char	*start;

	map_exit = ft_strchr(components[0] + 1, 'E');
	if (map_exit)
		throw_duplicate("exit", filename, map_exit, map);
	start = ft_strchr(components[1] + 1, 'P');
	if (start)
		throw_duplicate("start position", filename, start, map);
}

static void	throw_no_component(char *component, char *filename, char *map_str)
{
	free(map_str);
	ft_dprintf(STDERR_FILENO, ERR_NO_CMPN, component, filename);
	exit(EXIT_FAILURE);
}

void	find_components(char *filename, t_map map)
{
	char		*ptr[3];

	ptr[0] = ft_strchr(map.str, 'C');
	if (!ptr[0])
		throw_no_component("collectible", filename, map.str);
	ptr[1] = ft_strchr(map.str, 'E');
	if (!ptr[1])
		throw_no_component("exit", filename, map.str);
	ptr[2] = ft_strchr(map.str, 'P');
	if (!ptr[2])
		throw_no_component("start position", filename, map.str);
	find_duplicate(filename, ptr + 1, map);
}
