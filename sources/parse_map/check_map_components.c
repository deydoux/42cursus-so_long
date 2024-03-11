/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_components.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:11:59 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/11 13:21:58 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"

static bool	check_characters(t_map map, char *filename)
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
			return (true);
		}
		i++;
	}
	return (false);
}

static void	throw_duplicate(
	char *component, char *ptr, t_map map, char *filename)
{
	size_t	i;
	size_t	len;

	i = ptr - map.str;
	len = map.width + 1;
	ft_dprintf(STDERR_FILENO, ERR_DUP_CMPN, component, filename,
		i / len + 1, i % len + 1);
}

static bool	check_duplicate(char **components, t_map map, char *filename)
{
	char	*exit;
	char	*start;

	exit = ft_strchr(components[0] + 1, 'E');
	if (exit)
	{
		throw_duplicate("exit", exit, map, filename);
		return (true);
	}
	start = ft_strchr(components[1] + 1, 'P');
	if (start)
	{
		throw_duplicate("start position", start, map, filename);
		return (true);
	}
	return (false);
}

bool	check_map_components(t_map map, char *filename)
{
	char		*components[3];

	if (check_characters(map, filename))
		return (true);
	components[0] = ft_strchr(map.str, 'C');
	if (!components[0])
	{
		ft_dprintf(STDERR_FILENO, ERR_NO_CMPN, "collectible", filename);
		return (true);
	}
	components[1] = ft_strchr(map.str, 'E');
	if (!components[1])
	{
		ft_dprintf(STDERR_FILENO, ERR_NO_CMPN, "exit", filename);
		return (true);
	}
	components[2] = ft_strchr(map.str, 'P');
	if (!components[2])
	{
		ft_dprintf(STDERR_FILENO, ERR_NO_CMPN, "start position", filename);
		return (true);
	}
	return (check_duplicate(components + 1, map, filename));
}
