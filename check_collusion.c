/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collusion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:52:55 by helarras          #+#    #+#             */
/*   eventd: 2024/05/24 18:53:05 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_collusion(t_map *map, int new_x, int new_y)
{
    t_point top_left;
    t_point top_right;
    t_point bot_left;
    t_point bot_right;
    
    top_left.x = (new_x + 10) / TILE_SIZE;
    top_left.y = (new_y + 10) / TILE_SIZE;

    top_right.x = (new_x + PLAYER_SIZE - 10) / TILE_SIZE;
    top_right.y = (new_y + 10) / TILE_SIZE;

    bot_left.x = (new_x + 10) / TILE_SIZE;
    bot_left.y = (new_y + PLAYER_SIZE - 10) / TILE_SIZE;

    bot_right.x = (new_x + PLAYER_SIZE - 10) / TILE_SIZE;
    bot_right.y = (new_y + PLAYER_SIZE - 10) / TILE_SIZE;
    
    if (map->grid[top_left.y][top_left.x] == '1' ||
        map->grid[top_right.y][top_right.x] == '1' ||
        map->grid[bot_left.y][bot_left.x] == '1' ||
        map->grid[bot_right.y][bot_right.x] == '1') 
        return 0; 
    return 1; 
}
