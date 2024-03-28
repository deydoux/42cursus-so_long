/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:57:43 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/28 18:20:22 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H
# include "../init_loop.h"

# define CHAR_HEIGH		9
# define CHAR_WIDTH		6
# define COLLECT_ALT	512
# define CLEAR_SEQ		"\33[2K\r"
# define HEART_X_OFFSET	6
# define HEART_Y_OFFSET	27

bool	check_char_contact(char c, t_game game);
void	check_collect(t_game game);
void	check_exit(t_game game);
void	check_move(t_game *game);
void	check_rake(t_game *game);
void	render_frame(t_game game);

#endif
