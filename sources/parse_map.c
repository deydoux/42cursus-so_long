/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:31:27 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/21 18:14:08 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	line_len(char *line)
{
	size_t	len;

	len = 0;
	while (line[len] != '\n' && line[len])
		len++;
	return (len);
}

static void	read_map(int fd, size_t len, size_t size, char **map)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		*map = malloc(sizeof(char) * (size + 1));
		if (*map)
			*map[size] = 0;
		return ;
	}
	if (!len)
		len = line_len(line);
	if (line_len(line) == len)
	{
		read_map(fd, len, size + len + 1, map);
		if (*map)
		{
			ft_memcpy(*map + size, line, len);
			(*map)[size + len] = '\n';
		}
	}
	free(line);
}

char	*parse_map(char *path)
{
	int		fd;
	char	*map;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = NULL;
	read_map(fd, 0, 0, &map);
	close(fd);
	return (map);
}
