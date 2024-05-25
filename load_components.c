/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_components.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 22:12:26 by helarras          #+#    #+#             */
/*   Updated: 2024/05/25 22:22:38 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_components load_components(mlx_t *mlx)
{
    t_components components;

    components.brick = load_img_texture(mlx, "textures/brick.png");
    components.coin = load_img_texture(mlx, "textures/coin16.png");
    components.exit = malloc(2 * sizeof(mlx_image_t));
    components.exit[0] = load_img_texture(mlx, "textures/exit_closed.png");
    components.exit[1] = load_img_texture(mlx, "textures/exit_opened.png");
    return (components);
}