/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:57:43 by deydoux           #+#    #+#             */
/*   Updated: 2024/03/28 13:53:40 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H
# include "../init_loop.h"

bool	check_char_contact(char c, t_game game);
void	check_collect(t_game game);
void	check_exit(t_game game);
void	check_move(t_game *game);
void	check_rake(t_game *game);
void	render_frame(t_game game);

#endif
