/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_resources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:23:33 by helarras          #+#    #+#             */
/*   Updated: 2024/05/26 20:55:58 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void    clean_object(mlx_t *mlx, t_object *object)
{
    int i;

    if (!object || !object->sprites)
        return ;
    i = 0;
    while (object->sprites[i])
    {
        mlx_delete_image(mlx, object->sprites[i++]);
    }
    free(object->sprites);
    free(object);
}

void    clean_componenets(mlx_t *mlx, t_components *components)
{
    if (!components)
        return ;
    clean_object(mlx, components->brick);
    clean_object(mlx, components->coin);
    clean_object(mlx, components->exit);
}

void    clean_resources(t_event *event)
{
    t_player    *player;
    t_map       *map;


    player = event->player;
    map = event->map;
    free_player(event->mlx, player);
    free_map(map);
    clean_componenets(event->mlx, event->components);
    free(event->components);
    free(event);
}