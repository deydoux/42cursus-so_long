/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:09:39 by deydoux           #+#    #+#             */
/*   Updated: 2025/01/11 18:57:37 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

bool	check_args(int argc, char **argv, char **filename)
{
	int		i;
	size_t	len;

	i = 1;
	while (i < argc)
	{
		len = ft_strlen(argv[i]);
		if (len >= 4 && ft_strncmp(argv[i] + len - 4, ".ber", 4) == 0)
		{
			*filename = argv[i];
			return (false);
		}
		i++;
	}
	if (argc)
		ft_dprintf(STDERR_FILENO, ERR_USAGE, argv[0]);
	else
		ft_dprintf(STDERR_FILENO, ERR_USAGE, "so_long");
	return (true);
}
