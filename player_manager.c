/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klock <klock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:23:16 by helarras          #+#    #+#             */
/*   Updated: 2024/05/23 18:59:47 by klock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_texture_t **load_textures()
{
    mlx_texture_t **textures = malloc(sizeof(mlx_texture_t*) * 4);
    if (!textures)
        return NULL;
    textures[0] = mlx_load_png("textures/tile000.png");
    textures[1] = mlx_load_png("textures/tile004.png");
    textures[2] = mlx_load_png("textures/tile008.png");
    textures[3] = mlx_load_png("textures/tile012.png");
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
    }
    return sprites;
}

void    load_sprites(mlx_t *mlx, t_player *player)
{
    int i;

    i = 0;
    while (i < 4)
    {
        mlx_image_to_window(mlx, player->sprites[i], 0 , 0);
        player->sprites[i]->enabled = 0;
        i++;
    }
}

t_player    *load_player(mlx_t *mlx)
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
    load_sprites(mlx, player);
    player->x = 64;
    player->y = 64;
    player->speed_x = 0;
    player->speed_y = 0;
    player->direction_change = 1;
    player->current_frame = player->sprites[0];
    player->current_frame->instances[0].x = 64;
    player->current_frame->instances[0].y = 64;
    return (player);
}



void    render_player(mlx_t *mlx, t_player *player, int x, int y)
{
        mlx_image_to_window(mlx,player->current_frame, x , y);
}

void    set_player_speed(t_player *player, int speed_x, int speed_y)
{
    player->speed_x = speed_x;
    player->speed_y = speed_y;
}