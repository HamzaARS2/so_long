/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:34:42 by helarras          #+#    #+#             */
/*   Updated: 2024/05/22 18:51:09 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_exit_exists(t_list *map_list)
{
    t_list *current;
    int found;

    found = 0;
    if (!map_list)
        return (0);
    current = map_list;
    while (current)
    {
        if (ft_strchr(current->content, 'E'))
            found++;
        current = current->next;
    }
    if (found == 1)
        return (1);
    return (0);
}

int is_player_exists(t_list *map_list)
{
    t_list *current;
    int found;

    found = 0;
    if (!map_list)
        return (0);
    current = map_list;
    while (current)
    {
        if (ft_strchr(current->content, 'P'))
            found++;
        current = current->next;
    }
    if (found == 1)
        return (1);
    return (0);
}

int is_collectibles_exists(t_list *map_list)
{
    t_list *current;
    int found;

    found = 0;
    if (!map_list)
        return (0);
    current = map_list;
    while (current)
    {
        if (ft_strchr(current->content, 'C'))
            found++;
        current = current->next;
    }
    if (found > 0)
        return (1);
    return (0);
}