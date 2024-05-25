/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_resources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:23:33 by helarras          #+#    #+#             */
/*   Updated: 2024/05/25 22:53:51 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void    clean_resources(t_event event)
{
    t_player    *player;
    t_map       *map;

    player = event.player;
    map = event.map;
    free_player(event.mlx, player);
    free_map(map);
    mlx_delete_image(event.mlx, event.components.brick);
    mlx_delete_image(event.mlx, event.components.coin);
    mlx_delete_image(event.mlx, event.components.exit[0]);
    mlx_delete_image(event.mlx, event.components.exit[1]);
}