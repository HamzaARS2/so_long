/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:26:38 by helarras          #+#    #+#             */
/*   Updated: 2024/05/23 20:50:25 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int handle_input(void* param) {
    t_update *update = (t_update *)param;
    t_player *player;
    
    player = update->player;

    if (mlx_is_key_down(update->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(update->mlx);
	else if (mlx_is_key_down(update->mlx, MLX_KEY_UP))
        set_player_speed(player, 0, -5);
	else if (mlx_is_key_down(update->mlx, MLX_KEY_DOWN))
        set_player_speed(player, 0, 5);
	else if (mlx_is_key_down(update->mlx, MLX_KEY_LEFT))
        set_player_speed(player, -5, 0);
	else if (mlx_is_key_down(update->mlx, MLX_KEY_RIGHT))
        set_player_speed(player, 5, 0);
    else
        set_player_speed(player, 0, 0);
    return 0;
}

void render_game(t_update *update) {
    t_state *current_state;
    t_player *player;
    
    player = update->player;

    // Render the game world, player, enemies, collectibles, etc.
    for (int i = 0; i < 16; i++) {
        mlx_image_to_window(update->mlx, update->bg, 32 * i, 0);
    }   
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

mlx_image_t *get_bg(mlx_t *mlx)
{
    mlx_texture_t *texture = mlx_load_png("textures/brick.png");
    mlx_image_t *img = mlx_texture_to_image(mlx, texture);
    return (img); 
}


char    **get_map(t_list *data)
{
    t_list  *current;
    char    **map;
    size_t  map_size;
    size_t  i;

    map_size = ft_lstsize(data);
    if(!data)
        return (0);
    map = malloc((map_size + 1) * sizeof(char *));
    if (!map)
        return (0);
    i = 0;
    current = data;
    while (current)
    {
        map[i] = current->content;
        current = current->next;
        i++;
    }
    map[i] = 0;
    return (map);
}

int32_t	main(int ac, char *av[])
{
    mlx_t *mlx;
    t_player *player;
    t_update update;
    mlx_image_t *bg;
    t_list *data;
    char **map;
    
    data = read_data(av[1]);
    map = get_map(data);
    render_map(mlx, map);
    mlx = mlx_init(1088, 192, GAME_NAME, true);
    if (!mlx)
        return (EXIT_FAILURE);
    player = load_player(mlx);
    update = (t_update){mlx, player, bg};
    // render_game(&update);
    mlx_key_hook(mlx, &on_direction_change, &update);
    mlx_loop_hook(mlx, handle_input, &update);
    mlx_loop_hook(mlx, update_game, &update);
    mlx_loop(mlx);
    mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
