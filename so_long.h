/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:07:11 by helarras          #+#    #+#             */
/*   eventd: 2024/05/24 18:59:43 by helarras         ###   ########.fr       */
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

# define TILE_SIZE 64
# define PLAYER_SIZE 48
# define GAME_NAME "Game of the year"

typedef enum e_game_state
{
	s_state_menu,
	s_state_gameplay,
	s_state_game_over
}	t_state;

typedef struct s_point {
	int x;
	int y;
} t_point;

typedef struct s_player {
	mlx_t *mlx;
	mlx_image_t **sprites;
	mlx_image_t *current_frame;
	int direction;
	t_point point;
	int speed_x;
	int speed_y;
} t_player;

typedef struct s_map {
	char	**grid;
	size_t	width;
	size_t	height;
	t_point start_pos;
} t_map;

typedef struct s_object {
	mlx_image_t **sprites;
	mlx_image_t *current_frame;
	int hidden;
} t_object;

typedef struct s_components {
	t_object *coin;
	t_object *brick;
	t_object *exit;
} t_components;

typedef struct s_event {
	mlx_t *mlx;
	t_player *player;
	t_map	*map;
	t_components *components;
} t_event;





t_point get_starting_pos(char **map);


mlx_image_t   *load_img_texture(mlx_t *mlx,char *file_path);
void update_game(void* param);
void handle_input(void* param);
int    handle_error(unsigned char error);
int can_reach_all(t_map *map, int startY, int startX);
t_components *load_components(mlx_t *mlx);

void    clean_resources(t_event *event);
// utils
void    free_map(t_map *map);
void    free_player(mlx_t *mlx, t_player *player);
int	free_data(t_list **data);
// collusion checker
int check_collusion(t_map *map, int new_x, int new_y, char obj);
int get_collided_instance(mlx_image_t *img_obj, int new_x, int new_y);
//	render
t_event	*render_game(mlx_t *mlx, t_map *map);
void    render_map(mlx_t *mlx, t_map *map, t_components *components);

t_list  *read_data(char *file_path);
// comp_checker
int is_exit_exists(char **grid);
int is_player_exists(char **grid);
int is_collectibles_exists(char **grid);
//map_handler
int check_components(char **grid);
int check_map(char **map);
t_map   *get_map(char *file_path);
// is_walled
int check_wall(char *wall, int flag);
int is_walled(char **grid);

//player_loader
t_player    *load_player(mlx_t *mlx, t_point start_pos);
void    render_player(mlx_t *mlx, t_player *player);
void    set_player_speed(t_player *player, int speed_x, int speed_y);
// direction
void    on_direction_change(void *param);
void    set_direction(t_player *player, mlx_image_t *current_frame);

#endif