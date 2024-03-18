/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_errors.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:50:34 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/18 17:29:29 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_ERRORS_H
# define SO_LONG_ERRORS_H
# define ERR_CLOSE_MAP "Error\nMap not surrounded by walls at %s:%u:%u\n"
# define ERR_COL_POS "Error\nFailed to store collectible positions\n"
# define ERR_DUP_CMPN "Error\nDuplicate %s at %s:%u:%u in map file\n"
# define ERR_MAP_IMG "Error\nFailed to create map image\n"
# define ERR_MAP_RECT "Error\nLine length mismatch at %s:%u in map file\n"
# define ERR_MAP_SIZE "Error\nMap size too large with %upx sprites\n"
# define ERR_MLX_INIT "Error\nFailed to connect to X server\n"
# define ERR_NO_CMPN "Error\nNo %s found in %s map file\n"
# define ERR_NO_PATH "Error\nNo path found to validate %s map\n"
# define ERR_NEW_WIN "Error\nFailed to create window\n"
# define ERR_OPEN_IMG "Error\nFailed to open %s image file\n"
# define ERR_OPEN_MAP "Error\nFailed to open %s map file\n"
# define ERR_READ_MAP "Error\nFailed to read %s map file\n"
# define ERR_UEXP_CHAR "Error\nUnexpected '%c' character at %s:%u:%u\n"
# define ERR_USAGE "Error\nUsage: %s map_file.ber\n"
#endif
