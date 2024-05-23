/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:42:02 by helarras          #+#    #+#             */
/*   Updated: 2024/05/23 18:47:31 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    set_direction(t_player *player, mlx_image_t *current_frame)
{
    int i = 0;
    player->current_frame = current_frame;
    player->current_frame->instances[0].x = player->x;
    player->current_frame->instances[0].y = player->y;
    while (i < 4)
        player->sprites[i++]->enabled = 0;
    player->current_frame->enabled = 1;
}

void    on_direction_change(mlx_key_data_t keydata, void *param)
{
    t_update *update = (t_update *)param;
    t_player *player = update->player;
    
    if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
        set_direction(player, player->sprites[1]); 
    else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
        set_direction(player, player->sprites[2]);
    else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
        set_direction(player, player->sprites[3]);
    else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
        set_direction(player, player->sprites[0]);
}