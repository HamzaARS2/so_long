/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klock <klock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:07:11 by helarras          #+#    #+#             */
/*   Updated: 2024/05/24 05:46:50 by klock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/home/klock/MLX42/include/MLX42/MLX42.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define TILE_SIZE 32
# define GAME_NAME "Game of the year"

typedef enum e_game_state
{
	s_state_menu,
	s_state_gameplay,
	s_state_game_over
}	t_state;

typedef struct s_player {
	mlx_t *mlx;
	mlx_image_t **sprites;
	mlx_image_t *current_frame;
	int direction_change;
	int x;
	int y;
	int speed_x;
	int speed_y;
} t_player;

typedef struct s_map {
	char	**grid;
	size_t	width;
	size_t	height;
} t_map;

typedef struct s_update {
	mlx_t *mlx;
	t_player *player;
	t_map	*map;
} t_update;


mlx_image_t   *load_img_texture(mlx_t *mlx,char *file_path);
// map_loader
void    render_map(mlx_t *mlx, t_map *map);

t_list  *read_data(char *file_path);
// comp_checker
int is_exit_exists(t_list *map_list);
int is_player_exists(t_list *map_list);
int is_collectibles_exists(t_list *map_list);
//map_handler
int check_components(t_list *map_list);
int check_map(t_list *map_list);
t_map   *get_map(char *file_path);
// is_walled
int check_wall(char *wall, int flag);
int is_walled(t_list *map_list);

//player_loader
t_player    *load_player(mlx_t *mlx);
void    render_player(mlx_t *mlx, t_player *player, int x, int y);
void    set_player_speed(t_player *player, int speed_x, int speed_y);
// direction
void    on_direction_change(mlx_key_data_t keydata, void *param);

#endif