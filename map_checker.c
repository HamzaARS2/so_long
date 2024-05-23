/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:10:36 by helarras          #+#    #+#             */
/*   Updated: 2024/05/23 11:52:51 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int    handle_error(unsigned char error)
{
    if (error == 'E')
        ft_printf("Error\n%s\n", "Exit not found!");
    else if (error == 'M' + 'E')
        ft_printf("Error\n%s\n", "Multiple exits found!");
    else if (error == 'P')
        ft_printf("Error\n%s\n", "Player not found!");
    else if (error == 'M' + 'P')
        ft_printf("Error\n%s\n", "Multiple players found!");
    else if (error == 'C')
        ft_printf("Error\n%s\n", "Collectibles not found!");
    else if (error == 'R')
        ft_printf("Error\n%s\n", "The map is not rectangular");
    else if (error == 'W')
        ft_printf("Error\n%s\n", "The map is not walled!");
    else
        return (1);
    return (0);
}

static int is_rectangular(t_list *map_list)
{
    t_list *current;
    size_t row_size;
    size_t current_size;
    
    if (!map_list)
        return (0);
    current = map_list->next;
    row_size = ft_strlen((char *)map_list->content);
    while (current)
    {
        current_size = ft_strlen(current->content);
        if (!current->next)
        {
            if (row_size - 1 == current_size)
                return (1);
            if (current_size > row_size - 1)
                return ('R');
        }
        if (row_size != current_size)
            return ('R');
        current = current->next;
    }
    return (1);
}

int check_components(t_list *map_list)
{
    t_list *current;
    
    if (!map_list)
        return (0);
    if (!handle_error(is_player_exists(map_list)))
        return (0);
    if (!handle_error(is_exit_exists(map_list)))
        return (0);
    if (!handle_error(is_collectibles_exists(map_list)))
        return (0);
    return (1);
}

int check_map(t_list *map_list)
{
    if (!handle_error(is_rectangular(map_list)))
        return (0);
    if (!handle_error(is_walled(map_list)))
        return (0);
    return (check_components(map_list));
}