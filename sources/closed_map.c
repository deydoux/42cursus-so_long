/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:34:44 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/08 15:13:11 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	throw_closed_map(char *filename, size_t i, t_map map)
{
	size_t	len;

	len = map.width + 1;
	free(map.str);
	ft_dprintf(STDERR_FILENO, ERR_CLOSE_MAP, filename,
		i / len + 1, i % len + 1);
	exit(EXIT_FAILURE);
}

void	closed_map(char *filename, t_map map)
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
