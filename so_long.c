/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klock <klock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:26:38 by helarras          #+#    #+#             */
/*   Updated: 2024/05/23 18:13:15 by klock            ###   ########.fr       */
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

void update_game(void* param) {
    t_update *update = (t_update *)param;
    t_player *player = update->player;
    
    // Update player, enemies, collectibles, etc.
    player->current_frame->instances[0].x += player->speed_x;
    player->current_frame->instances[0].y += player->speed_y;
    player->x = player->current_frame->instances[0].x;
    player->y = player->current_frame->instances[0].y;
    
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
    update = (t_update){mlx, player};
    mlx_key_hook(mlx, &on_direction_change, &update);
    mlx_loop_hook(mlx, handle_input, &update);
    mlx_loop_hook(mlx, update_game, &update);
    mlx_loop(mlx);
    mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
