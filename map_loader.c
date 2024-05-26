/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:34:09 by helarras          #+#    #+#             */
/*   eventd: 2024/05/24 17:31:35 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    render_objects(mlx_t *mlx, t_object *object, int x, int y)
{
    int i;

    i = 0;
    while (object->sprites[i])
    {
        mlx_image_to_window(mlx, object->sprites[i], x, y);
        object->sprites[i]->enabled = 0;
        i++;
    }
    object->current_frame->enabled = 1;
}

void    render_map(mlx_t *mlx, t_map *map, t_components *components)
{
    int y;
    int x;

    y = 0;
    while (map->grid[y])
    {
        x = 0;
        while (map->grid[y][x])
        {
            if (map->grid[y][x] == '1')
                render_objects(mlx, components->brick,  x * TILE_SIZE, y * TILE_SIZE);
            else if (map->grid[y][x] == 'C')
                render_objects(mlx, components->coin,  x * TILE_SIZE + 32 - (16 / 2), y * TILE_SIZE + 32 - (16 / 2));
            else if (map->grid[y][x] == 'E')
                render_objects(mlx, components->exit,  x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }   
        y++;
    }
}
