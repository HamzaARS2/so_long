/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_starting_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:47:11 by helarras          #+#    #+#             */
/*   eventd: 2024/05/24 17:52:39 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point get_starting_pos(char **map)
{
    int i;
    int k;

    i = 0;
    while (map[i])
    {
        k = 0;
        while (map[i][k])
        {
            if (map[i][k] == 'P')
            return ((t_point){k * TILE_SIZE, i * TILE_SIZE});        
            k++;
        }
        i++;
    }
    return ((t_point){0});
}