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

void    check_direction(t_player *player)
{
    if (player->direction == 0) {
        // idle

        set_direction(player, player->sprites[0]);
    } else if (player->direction == 1) {
        // right
        set_direction(player, player->sprites[1]);
    } else if (player->direction == 2) {
        // left
        set_direction(player, player->sprites[2]);
    } else if (player->direction == 3) {
        // up
        set_direction(player, player->sprites[3]);
    } else if (player->direction == 4) {
        // down
        // TODO: add down sprites in the sprites[4]
        set_direction(player, player->sprites[0]);
    }
}

void    hide_object_instance(t_object *object, int instance)
{
    int i;

    if (instance == -1 || !object->current_frame->instances[instance].enabled)
        return ;
    object->hidden++;
    i = 0;
    while (object->sprites[i])
        object->sprites[i++]->instances[instance].enabled = 0;
}


void handle_coin_collision(t_event *event) {
    t_player *player = event->player;
    int new_x = player->point.x;
    int new_y = player->point.y;

    if (!check_collusion(event->map, new_x, new_y, 'C')) {
        int instance = get_collided_instance(event->components->coin->current_frame, new_x, new_y);
        hide_object_instance(event->components->coin, instance);
    }
}

void check_all_coins_collected(t_object *coin, t_object *exit) {
    if (coin->hidden >= coin->current_frame->count && !exit->sprites[1]->enabled) {
        printf("All coins collected!\n");
        exit->sprites[0]->enabled = 0;
        exit->sprites[1]->enabled = 1;
    }
}

void    on_player_exit(t_event *event)
{
    t_player *player = event->player;
    t_object *exit = event->components->exit;
    int new_x = player->point.x;
    int new_y = player->point.y;

    if (!check_collusion(event->map, new_x + PLAYER_SIZE / 2, new_y + PLAYER_SIZE / 2, 'E') && exit->sprites[1]->enabled) {
        mlx_close_window(event->mlx);
    }
}

void update_player_position(t_player *player, int new_x, int new_y) {
    player->current_frame->instances[0].x = new_x;
    player->current_frame->instances[0].y = new_y;
    player->point.x = new_x;
    player->point.y = new_y;
   
}

void update_game(void* param) {
    t_event *event = (t_event *)param;
    t_player *player = event->player;
    int new_x = player->point.x + player->speed_x;
    int new_y = player->point.y + player->speed_y;

    check_direction(player);
    // if (check_collusion(event->map, new_x, new_y, '1')) {
    //     update_player_position(player, new_x, new_y);
    // }

     if (new_x != player->point.x || new_y != player->point.y) {
        if (check_collusion(event->map, new_x, new_y, '1')) {
            update_player_position(player, new_x, new_y);
            player->moves++; // Increment move count only if the player actually moves
            printf("Moves: %d\n", player->moves); // Print move count to shell
        }
    }

    handle_coin_collision(event);
    check_all_coins_collected(event->components->coin, event->components->exit);
    on_player_exit(event);
}






// void update_game(void* param) {
//     t_event *event = (t_event *)param;
//     t_player *player = event->player;
//     int new_x = player->point.x + player->speed_x;
//     int new_y = player->point.y + player->speed_y;
//     int instance;
//     // event player, enemies, collectibles, etc.
//     check_direction(player);
//     if (check_collusion(event->map, new_x, new_y, '1')) 
//     {
//         player->current_frame->instances[0].x = new_x;
//         player->current_frame->instances[0].y = new_y;
//         player->point.x = new_x;
//         player->point.y = new_y;
//     }
//     if (!check_collusion(event->map, new_x, new_y, 'C'))
//     {
//         instance = get_collided_instance(event->components->coin->current_frame, new_x, new_y);
//         hide_object_instance(event->components->coin, instance);
//     }
//         if (event->components->coin->hidden >= event->components->coin->current_frame->count) {
//             printf("DETECTED!\n");

//         event->components->exit->sprites[0]->enabled = 0;
//         event->components->exit->sprites[1]->enabled = 1;
//         }
// }
