/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:09:39 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/28 13:10:00 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

bool	check_args(int argc, char **argv)
{
	bool	error;
	size_t	len;

	error = argc != 2;
	if (!error)
	{
		len = ft_strlen(argv[1]);
		error = len < 4;
		if (!error)
			error = ft_strncmp(argv[1] + len - 4, ".ber", 4) != 0;
	}
	if (error)
	{
		if (argc)
			ft_dprintf(STDERR_FILENO, ERR_USAGE, argv[0]);
		else
			ft_dprintf(STDERR_FILENO, ERR_USAGE, "so_long");
		return (true);
	}
	return (false);
}
