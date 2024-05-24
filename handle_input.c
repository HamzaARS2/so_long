/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:54:13 by helarras          #+#    #+#             */
/*   eventd: 2024/05/24 18:59:43 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void handle_input(void* param) {
    t_event *event = (t_event *)param;
    t_player *player;
    
    player = event->player;

    if (mlx_is_key_down(event->mlx, MLX_KEY_ESCAPE))
	mlx_close_window(event->mlx);
	else if (mlx_is_key_down(event->mlx, MLX_KEY_UP))
        set_player_speed(player, 0, -5);
	else if (mlx_is_key_down(event->mlx, MLX_KEY_DOWN))
        set_player_speed(player, 0, 5);
	else if (mlx_is_key_down(event->mlx, MLX_KEY_LEFT))
        set_player_speed(player, -5, 0);
	else if (mlx_is_key_down(event->mlx, MLX_KEY_RIGHT))
        set_player_speed(player, 5, 0);
    else
        set_player_speed(player, 0, 0);
}
