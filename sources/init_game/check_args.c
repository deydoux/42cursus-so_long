/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:09:39 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/28 15:16:14 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

static bool	check_ber_ext(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	return (len < 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0);
}

bool	check_args(int argc, char **argv, char *hard)
{
	bool	error;

	error = 2 > argc || argc > 3 - !HARD_FLAG;
	*hard = !error && argc == 3 && ft_strcmp(argv[1], "-h") == 0;
	if (error || check_ber_ext(argv[1 + *hard]))
	{
		if (argc)
			ft_dprintf(STDERR_FILENO, ERR_USAGE, argv[0]);
		else
			ft_dprintf(STDERR_FILENO, ERR_USAGE, "so_long");
		return (true);
	}
	if (!error && !*hard && argc == 3)
		*hard = (ft_strcmp(argv[2], "-h") == 0) * 2;
	return (false);
}
