/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:42:02 by helarras          #+#    #+#             */
/*   eventd: 2024/05/24 18:59:43 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    set_direction(t_player *player, mlx_image_t *current_frame)
{
    int i = 0;
    player->current_frame = current_frame;
    player->current_frame->instances[0].x = player->point.x;
    player->current_frame->instances[0].y = player->point.y;
    while (i < 4)
        player->sprites[i++]->enabled = 0;
    player->current_frame->enabled = 1;

}

void    on_direction_change(void *param)
{
   t_event *event = (t_event *)param;
    t_player *player = event->player;
    
    // printf("direction: %i\n", player->direction);
    if (mlx_is_key_down(event->mlx, MLX_KEY_RIGHT))
        player->direction = 1;
	else if (mlx_is_key_down(event->mlx, MLX_KEY_LEFT))
        player->direction = 2;
	else if (mlx_is_key_down(event->mlx, MLX_KEY_UP))
        player->direction = 3;
	else if (mlx_is_key_down(event->mlx, MLX_KEY_DOWN))
        player->direction = 0;
    else
        player->direction = 0;
}

