/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:35:46 by helarras          #+#    #+#             */
/*   eventd: 2024/05/23 19:38:32 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t   *load_img_texture(mlx_t *mlx,char *file_path)
{
    mlx_texture_t   *texture;
    mlx_image_t     *image;

    texture = mlx_load_png(file_path);
    image = mlx_texture_to_image(mlx, texture);

    return (image);
}