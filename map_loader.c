/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:34:09 by helarras          #+#    #+#             */
/*   Updated: 2024/05/23 20:39:55 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    render_map(mlx_t *mlx, char **map)
{
    int i;
    int k;
    mlx_image_t *brick;

    i = 0;
    brick = load_img_texture(mlx, "textures/brick.png");
    while (map[i])
    {
        k = 0;
        while (map[i][k])
        {
            if (map[i][k] == '1')
                 mlx_image_to_window(mlx, brick, 32 * k, 32 * i);
            k++;
        }   
        i++;
    }
    
}