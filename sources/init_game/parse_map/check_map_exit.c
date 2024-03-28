/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:44:42 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/28 12:53:16 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"

bool	check_map_exit(t_map map, char *filename)
{
	size_t	i;

	i = 0;
	while (map.str[i] != 'E' && map.str[i])
		i++;
	if (!map.str[i])
	{
		ft_dprintf(STDERR_FILENO, ERR_NO_CMPN, "exit", filename);
		return (true);
	}
	while (map.str[++i])
	{
		if (map.str[i] == 'E')
		{
			ft_dprintf(STDERR_FILENO, ERR_DUP_CMPN, "exit", filename,
				i / map.width + 1, i % map.width + 1);
			return (true);
		}
	}
	return (false);
}
