/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 22:58:09 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/24 21:34:39 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"

static void	propagate_path(size_t position, t_map map)
{
	if (ft_strchr(".1cep", map.str[position]))
		return ;
	if (map.str[position] == '0')
		map.str[position] = '.';
	else
		map.str[position] = ft_tolower(map.str[position]);
	propagate_path(position + 1, map);
	propagate_path(position - 1, map);
	propagate_path(position + map.width, map);
	propagate_path(position - map.width, map);
}

static void	revert_propagation(char *str)
{
	while (*str)
	{
		if (*str == '.')
			*str = '0';
		else
			*str = ft_toupper(*str);
		str++;
	}
}

bool	check_valid_path(t_map map, char *filename)
{
	propagate_path(ft_strchr(map.str, 'P') - map.str, map);
	if (ft_strchr(map.str, 'C') || ft_strchr(map.str, 'E'))
	{
		ft_dprintf(STDERR_FILENO, ERR_NO_PATH, filename);
		return (true);
	}
	revert_propagation(map.str);
	return (false);
}
