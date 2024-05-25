/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:54:28 by helarras          #+#    #+#             */
/*   eventd: 2024/05/24 18:59:43 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void update_game(void* param) {
    t_event *event = (t_event *)param;
    t_player *player = event->player;
    int new_x = player->point.x + player->speed_x;
    int new_y = player->point.y + player->speed_y;
    int instance;
    // event player, enemies, collectibles, etc.
    if (check_collusion(event->map, new_x, new_y, '1')) 
    {
        player->current_frame->instances[0].x = new_x;
        player->current_frame->instances[0].y = new_y;
        player->point.x = new_x;
        player->point.y = new_y;
    }
    if (!check_collusion(event->map, new_x, new_y, 'C'))
    {
        instance = get_collided_instance(event->components.coin, new_x, new_y);
        if (instance != -1) 
            event->components.coin->instances[instance].enabled = 0;
    }
    
}
