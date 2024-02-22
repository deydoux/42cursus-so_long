/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:31:27 by deydoux           #+#    #+#             */
/*   Updated: 2024/02/22 17:28:18 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	valid_char(char c, t_parse *parse)
{
	if (c == '0' || c == '1')
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
		if (!parse.collectible || !parse.exit || !parse.start)
			return ;
		map->content = malloc(sizeof(char) * (size + 1));
		if (map->content)
			map->content[size] = 0;
		return ;
	}
	if (valid_line(line, &map->line_len, &parse))
	{
		read_map(fd, size + map->line_len + 1, parse, map);
		if (map->content)
		{
			ft_memcpy(map->content + size, line, map->line_len);
			map->content[size + map->line_len] = '\n';
		}
	}
	free(line);
}

t_map	parse_map(char *path)
{
	int		fd;
	t_map	map;
	t_parse	parse;

	map.content = NULL;
	fd = open(path, O_RDONLY);
	if (fd != -1)
	{
		map.line_len = 0;
		parse.collectible = false;
		parse.exit = false;
		parse.start = false;
		read_map(fd, 0, parse, &map);
		close(fd);
	}
	if (!map.content)
	{
		ft_putstr_fd("Error\nParsing failed\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (map);
}
