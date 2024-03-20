/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_components.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:11:59 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/19 14:03:52 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"

static bool	check_map_component(char c, char *name, t_map map, char *filename)
{
	size_t	i;

	i = 0;
	while (map.str[i] != c && map.str[i])
		i++;
	if (!map.str[i])
	{
		ft_dprintf(STDERR_FILENO, ERR_NO_CMPN, name, filename);
		return (true);
	}
	while (map.str[++i])
	{
		if (map.str[i] == c)
		{
			ft_dprintf(STDERR_FILENO, ERR_DUP_CMPN, name, filename,
				i / (map.size.x + 1) + 1, i % (map.size.x + 1) + 1);
			return (true);
		}
	}
	return (false);
}

bool	check_map_components(t_map map, char *filename)
{
	return (check_map_component('E', "exit", map, filename)
		|| check_map_component('P', "start position", map, filename));
}
