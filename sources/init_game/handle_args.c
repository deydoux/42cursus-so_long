/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:29:34 by deydoux           #+#    #+#             */
/*   Updated: 2025/01/13 13:54:39 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

static void	put_usage(char *program, int status)
{
	ft_dprintf(STDERR_FILENO, USAGE, program);
	exit(status);
}

static bool	get_filename(char *arg, char **filename)
{
	size_t	len;

	len = ft_strlen(arg);
	if (len < 4 || ft_strncmp(arg + len - 4, ".ber", 4) != 0)
		return (true);
	*filename = arg;
	return (false);
}

bool	handle_args(int argc, char **argv, t_game *game)
{
	char	*filename;
	int		i;

	filename = NULL;
	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "-h", 3) == 0
			|| ft_strncmp(argv[i], "--help", 7) == 0)
			put_usage(argv[0], EXIT_SUCCESS);
		else if (ft_strncmp(argv[i], "-k", 3) == 0
			|| ft_strncmp(argv[i], "--keys", 7) == 0)
		{
			if (++i >= argc || ft_strlen(argv[i]) != 4)
				put_usage(argv[0], EXIT_FAILURE);
			game->key.conf = (t_key_conf){argv[i][0], argv[i][1], argv[i][2],
				argv[i][3]};
		}
		else if (get_filename(argv[i], &filename))
			put_usage(argv[0], EXIT_FAILURE);
		i++;
	}
	if (!filename)
		put_usage(argv[0], EXIT_FAILURE);
	return (parse_map(filename, &game->map));
}
