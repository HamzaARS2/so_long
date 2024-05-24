/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klock <klock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:26:38 by helarras          #+#    #+#             */
/*   Updated: 2024/05/24 05:51:41 by klock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void handle_input(void* param) {
    t_update *update = (t_update *)param;
    t_player *player;
    
    player = update->player;

    if (mlx_is_key_down(update->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(update->mlx);
	else if (mlx_is_key_down(update->mlx, MLX_KEY_UP))
        set_player_speed(player, 0, -2);
	else if (mlx_is_key_down(update->mlx, MLX_KEY_DOWN))
        set_player_speed(player, 0, 2);
	else if (mlx_is_key_down(update->mlx, MLX_KEY_LEFT))
        set_player_speed(player, -2, 0);
	else if (mlx_is_key_down(update->mlx, MLX_KEY_RIGHT))
        set_player_speed(player, 2, 0);
    else
        set_player_speed(player, 0, 0);
}

int check_collusion(t_update *update, int new_x, int new_y) {
    t_map *map = update->map;
    int top_left_x = new_x / TILE_SIZE;
    int top_left_y = new_y / TILE_SIZE;

    int top_right_x = (new_x + TILE_SIZE - 1) / TILE_SIZE;
    int top_right_y = new_y / TILE_SIZE;

    int bottom_left_x = new_x / TILE_SIZE;
    int bottom_left_y = (new_y + TILE_SIZE - 1) / TILE_SIZE;

    int bottom_right_x = (new_x + TILE_SIZE - 1) / TILE_SIZE;
    int bottom_right_y = (new_y + TILE_SIZE - 1) / TILE_SIZE;

    // Check if any of the corners collide with a wall
    if (map->grid[top_left_y][top_left_x] == '1' ||
        map->grid[top_right_y][top_right_x] == '1' ||
        map->grid[bottom_left_y][bottom_left_x] == '1' ||
        map->grid[bottom_right_y][bottom_right_x] == '1') {
        return 0; // Collision detected
    }
    return 1; //
}

void update_game(void* param) {
    t_update *update = (t_update *)param;
    t_player *player = update->player;
    int new_x = player->x + player->speed_x;
    int new_y = player->y + player->speed_y;
    // Update player, enemies, collectibles, etc.
    if (check_collusion(update, new_x, new_y)) {
        player->current_frame->instances[0].x = new_x;
        player->current_frame->instances[0].y = new_y;
        player->x = new_x;
        player->y = new_y;
    }
    
}


int32_t	main(int ac, char *av[])
{
    mlx_t *mlx;
    t_player *player;
    t_update update;
    t_map *map;
    
    map = get_map(av[1]);
    if (!map)
        return (EXIT_FAILURE);
    mlx = mlx_init(map->width,map->height, GAME_NAME, true);
    if (!mlx)
        return (EXIT_FAILURE);
    render_map(mlx, map);
    player = load_player(mlx);
    update = (t_update){mlx, player, map};
    mlx_key_hook(mlx, &on_direction_change, &update);
    mlx_loop_hook(mlx, handle_input, &update);
    mlx_loop_hook(mlx, update_game, &update);
    mlx_loop(mlx);
    mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
