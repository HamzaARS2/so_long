/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:34:42 by helarras          #+#    #+#             */
/*   Updated: 2024/05/23 11:40:07 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int comp_count(char *row, char comp)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (row[i])
        if (row[i++] == comp)
            count++;
    return (count);
}

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
        found += comp_count(current->content, 'E');
        current = current->next;
    }
    if (found == 1)
        return (1);
    else if (found > 1)
        return ('M' + 'E');
    return ('E');
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
        found += comp_count(current->content, 'P');
        current = current->next;
    }
    if (found == 1)
        return (1);
    else if (found > 1)
        return ('M' + 'P');
    return ('P');
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
    return ('C');
}