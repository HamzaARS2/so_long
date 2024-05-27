/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:23:16 by helarras          #+#    #+#             */
/*   eventd: 2024/05/24 18:36:51 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


mlx_texture_t **load_textures()
{
    mlx_texture_t **textures = malloc(sizeof(mlx_texture_t*) * 4);
    if (!textures)
        return NULL;
    textures[0] = mlx_load_png("textures/down_walk_0.png");
    textures[1] = mlx_load_png("textures/right_walk_0.png");
    textures[2] = mlx_load_png("textures/left_walk_0.png");
    textures[3] = mlx_load_png("textures/up_walk_0.png");
    return textures;
}
mlx_image_t **create_sprites(mlx_t *mlx, mlx_texture_t **textures, int num_textures)
{
    mlx_image_t **sprites = malloc(sizeof(mlx_image_t*) * num_textures);
    if (!sprites)
        return NULL;

    for (int i = 0; i < num_textures; i++) {
        sprites[i] = mlx_texture_to_image(mlx, textures[i]);
        if (!sprites[i]) {
            for (int j = 0; j < i; j++) {
                mlx_delete_image(mlx, sprites[j]);
            }
            free(sprites);
            return NULL;
        }
        mlx_delete_texture(textures[i]);
    }
    free(textures);
    return sprites;
}

void    load_sprites(mlx_t *mlx, t_player *player)
{
    int i;

    i = 0;
    while (i < 4)
    {
        mlx_image_to_window(mlx, player->sprites[i], player->point.x , player->point.y);
        player->sprites[i]->enabled = 0;
        i++;
    }
    player->current_frame->enabled = 1;
}

t_player    *load_player(mlx_t *mlx, t_point start_pos)
{
    int i;
    t_player *player;
    mlx_texture_t **textures;

    player = malloc(sizeof(t_player));
    textures = load_textures();
    if (!textures)
        return (0);
    player->sprites = create_sprites(mlx, textures, 4);
    if (!player->sprites)
        return (0);
    player->point = start_pos;
    player->speed_x = 0;
    player->speed_y = 0;
    player->direction = 0;
    player->moves = 0;
    player->current_frame = player->sprites[0];
    
    return (player);
}



void    render_player(mlx_t *mlx, t_player *player)
{
    load_sprites(mlx, player);
}

void    set_player_speed(t_player *player, int speed_x, int speed_y)
{
    player->speed_x = speed_x;
    player->speed_y = speed_y;
}