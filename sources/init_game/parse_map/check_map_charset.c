/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_charset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:33:52 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/28 12:34:23 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"

bool	check_map_charset(t_map map, char *filename)
{
	size_t	i;

	i = 0;
	while (map.str[i])
	{
		if (!ft_strchr(MAP_CHARSET, map.str[i]))
		{
			ft_dprintf(STDERR_FILENO, ERR_UEXP_CHAR, map.str[i], filename,
				i / map.width + 1, i % map.width + 1);
			return (true);
		}
		i++;
	}
	return (false);
}
