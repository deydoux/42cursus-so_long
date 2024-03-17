/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:31:27 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/17 22:48:21 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"

static bool	init_map_str(size_t size, char **map_str)
{
	if (!errno)
	{
		*map_str = malloc(sizeof(char) * (size + 1));
		if (*map_str)
			(*map_str)[size] = 0;
	}
	return (false);
}

static size_t	line_len(char *line)
{
	size_t	len;

	len = 0;
	while (line[len] != '\n' && line[len])
		len++;
	return (len);
}

static bool	copy_map_str(int fd, size_t size, t_map *map)
{
	char	*line;
	size_t	len;

	errno = 0;
	line = get_next_line(fd);
	if (!line)
		return (init_map_str(size, &map->str));
	len = line_len(line);
	if (!map->heigh++)
		map->width = len;
	else if (map->width != len)
		fd = -1;
	if (fd == -1 || copy_map_str(fd, size + len + 1, map))
		fd = -1;
	else if (map->str)
	{
		ft_memcpy(map->str + size, line, len);
		map->str[size + len] = '\n';
	}
	free(line);
	return (fd == -1);
}

bool	read_map(char *filename, t_map *map)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_dprintf(STDERR_FILENO, ERR_OPEN_MAP, filename);
		return (true);
	}
	map->str = NULL;
	map->heigh = 0;
	if (copy_map_str(fd, 0, map))
	{
		ft_dprintf(STDERR_FILENO, ERR_MAP_RECT, filename, map->heigh);
		return (true);
	}
	close(fd);
	if (!map->str)
	{
		ft_dprintf(STDERR_FILENO, ERR_READ_MAP, filename);
		return (true);
	}
	return (false);
}
