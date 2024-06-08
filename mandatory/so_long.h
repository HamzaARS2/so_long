/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:17:49 by helarras          #+#    #+#             */
/*   Updated: 2024/06/05 13:13:57 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "/Users/helarras/MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <unistd.h>

# define TILE_SIZE 64
# define PLAYER_SIZE 48
# define COIN_SIZE 18
# define GAME_NAME "so_long"

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct s_moves
{
	size_t			count;
	mlx_image_t		*img;
	int				move_delay;
}					t_moves;

typedef struct s_player
{
	mlx_t			*mlx;
	mlx_image_t		***sprites;
	int				current_frame;
	int				direction;
	t_point			point;
	int				speed_x;
	int				speed_y;
	t_moves			moves;
}					t_player;

typedef struct s_map
{
	char			**grid;
	size_t			width;
	size_t			height;
	t_point			start_pos;
}					t_map;

typedef struct s_object
{
	mlx_image_t		**sprites;
	int				current_frame;
	int				frame_delay;
	size_t			hidden;
}					t_object;

typedef struct s_components
{
	t_object		*coin;
	t_object		*brick;
	t_object		*exit;
	t_object		*bg;
}					t_components;

typedef struct s_event
{
	mlx_t			*mlx;
	t_player		*player;
	t_map			*map;
	t_components	*components;
}					t_event;

void				change_frames_pos(mlx_image_t **frames, int x, int y);
void				display_cframe(mlx_image_t **frames, int current_frame);
void				display_cdirection_frame(t_player *player);
t_point				get_starting_pos(char **map, char c);
void				*free_map_data(t_map *map, t_list *data);
mlx_image_t			*load_img_texture(mlx_t *mlx, char *file_path);
void				update_game(void *param);
void				handle_input(void *param);
int					handle_error(unsigned char error);
int					can_reach_all(t_map *map, int startY, int startX);
t_components		*load_components(mlx_t *mlx);
void				count_moves(t_player *player);
void				clean_resources(t_event *event, int status);
void				check_all_coins_collected(t_object *coin, t_object *exit);
int					check_invalid_chars(char **map);
int					comp_count(char *row, char comp);
char				**get_down_textures(void);
char				**get_up_textures(void);
char				**get_right_textures(void);
char				**get_left_textures(void);
void				free_sprites(mlx_t *mlx, mlx_image_t **sprites,
						int num_textures);
mlx_image_t			***create_sprites(mlx_t *mlx);
void				load_sprites(mlx_t *mlx, t_player *player);
int					free_map(t_map *map);
void				free_player(mlx_t *mlx, t_player *player);
int					free_data(t_list **data);
int					check_collision(t_map *map, int new_x, int new_y, char obj);
int					get_collided_instance(mlx_image_t *img_obj, int new_x,
						int new_y);
t_event				*render_game(mlx_t *mlx, t_map *map);
void				render_map(mlx_t *mlx, t_map *map,
						t_components *components);
t_list				*read_data(char *file_path);
int					is_exit_exists(char **grid);
int					is_player_exists(char **grid);
int					is_collectibles_exists(char **grid);
int					check_components(char **grid);
int					check_map(t_map *map);
t_map				*get_map(char *file_path);
int					check_wall(char *wall, int flag);
int					is_walled(char **grid);
t_player			*load_player(mlx_t *mlx, t_point start_pos);
void				render_player(mlx_t *mlx, t_player *player);
void				set_player_speed(t_player *player, int speed_x,
						int speed_y);
void				render_objects(mlx_t *mlx, t_object *object, int x, int y);

#endif
