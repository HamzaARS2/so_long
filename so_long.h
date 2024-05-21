/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:07:11 by helarras          #+#    #+#             */
/*   Updated: 2024/05/21 16:05:35 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/Users/helarras/MLX42/include/MLX42/MLX42.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define WIDTH 720
# define HEIGHT 480
# define GAME_NAME "Game of the year"

typedef enum e_game_state
{
	s_state_menu,
	s_state_gameplay,
	s_state_game_over
}	t_state;

char    *read_map(char *file_path);

#endif