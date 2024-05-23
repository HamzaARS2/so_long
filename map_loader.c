/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klock <klock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:34:09 by helarras          #+#    #+#             */
/*   Updated: 2024/05/23 18:14:53 by klock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    render_map(mlx_t *mlx, t_map *map)
{
    int i;
    int k;
    mlx_image_t *brick;
    mlx_image_t *coin;

    i = 0;
    brick = load_img_texture(mlx, "textures/brick.png");
    coin = load_img_texture(mlx, "textures/coin.png");
    while (map->grid[i])
    {
        k = 0;
        while (map->grid[i][k])
        {
            if (map->grid[i][k] == '1')
                mlx_image_to_window(mlx, brick, k * TILE_SIZE, i * TILE_SIZE);
            else if (map->grid[i][k] == 'C')
                mlx_image_to_window(mlx, coin, k * TILE_SIZE, i * TILE_SIZE);
            k++;
        }   
        i++;
    }
}
