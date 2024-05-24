/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_walled.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:25:27 by helarras          #+#    #+#             */
/*   eventd: 2024/05/23 11:53:35 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_wall(char *wall, int flag)
{
    int i;
    size_t wall_size;
    
    wall_size = ft_strlen(wall);
    if (!flag)
        return (wall[0] == '1' && wall[wall_size - 2] == '1');
    i = 0;
    while (wall[i] && wall[i] != '\n')
    {
        if (wall[i++] != '1')
            return (0);
    }
    return (1);
}

int is_walled(t_list *map_list)
{
    t_list  *current;
    int     broken;

    
    if (!map_list)
        return (0);
    current = map_list->next;
    broken = check_wall(map_list->content, 1);
    
    while (current && broken)
    {
        if (!current->next)
            broken = check_wall(current->content, 1);
        else
            broken = check_wall(current->content, 0);
        current = current->next;
    }
    if (!broken)
        return ('W');
    return (broken);
}