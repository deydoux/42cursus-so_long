/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:31:27 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/28 12:56:56 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	valid_char(char c, t_parse *parse)
{
	if (c == '1')
		return (true);
	parse->last = false;
	if (c == '0')
		return (true);
	if (c == 'C')
		parse->collectible = true;
	else if (c == 'E')
	{
		if (parse->exit)
			return (false);
		parse->exit = true;
	}
	else if (c == 'P')
	{
		if (parse->start)
			return (false);
		parse->start = true;
	}
	else
		return (false);
	return (true);
}

static bool	valid_line(char *line, size_t *len, t_parse *parse)
{
	size_t	i;

	if (!*len)
	{
		while (line[*len] == '1')
			(*len)++;
		return (*len > 2 && line[*len] == '\n');
	}
	if (line[0] != '1')
		return (false);
	parse->last = true;
	i = 1;
	while (line[i] != '\n' && line[i])
		if (!valid_char(line[i++], parse))
			return (false);
	return (i == *len && line[i - 1] == '1');
}

static void	read_map(int fd, size_t size, t_parse parse, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		if (!parse.collectible || !parse.exit || !parse.start || !parse.last)
			return ;
		map->str = malloc(sizeof(char) * (size + 1));
		if (map->str)
			map->str[size] = 0;
		return ;
	}
	if (valid_line(line, &map->width, &parse))
	{
		map->heigh++;
		read_map(fd, size + map->width + 1, parse, map);
		if (map->str)
		{
			ft_memcpy(map->str + size, line, map->width);
			map->str[size + map->width] = '\n';
		}
	}
	free(line);
}

void	parse_map(char *path, t_map *map)
{
	int		fd;
	t_parse	parse;

	map->str = NULL;
	fd = open(path, O_RDONLY);
	if (fd != -1)
	{
		map->heigh = 0;
		map->width = 0;
		parse.collectible = false;
		parse.exit = false;
		parse.start = false;
		read_map(fd, 0, parse, map);
		close(fd);
	}
	if (!map->str)
	{
		ft_putstr_fd("Error\nFailed to parse map\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	valid_path(map);
}
